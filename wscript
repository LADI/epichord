#! /usr/bin/env python
#
# SPDX-FileCopyrightText:  2023 Nedko Arnaudov
# SPDX-License-Identifier: GPL-2.0-or-later

import os
import shutil

from waflib import Logs, Options
from waflib import Context

VERSION = "1.0.1"
APPNAME = 'epichord'

# these variables are mandatory ('/' are converted automatically)
top = '.'
out = 'build'

def options(opt):
    # options provided by the modules
    opt.load('compiler_cxx')
    opt.load('autooptions')

    opt.add_option('--libdir', type='string', help='Library directory [Default: <prefix>/lib64]')
    opt.add_option('--pkgconfigdir', type='string', help='pkg-config file directory [Default: <libdir>/pkgconfig]')

class WafToolchainFlags:
    """
    Waf helper class for handling set of CFLAGS
    and related. The flush() method will
    prepend so to allow supplied by (downstream/distro/builder) waf caller flags
    to override the upstream flags in wscript.
    TODO: upstream this or find alternative easy way of doing the same
    """
    def __init__(self, conf):
        """
        :param conf: Waf configuration object
        """
        self.conf = conf
        self.flags = {}
        for x in ('CPPFLAGS', 'CFLAGS', 'CXXFLAGS', 'LINKFLAGS'):
            self.flags[x] = []

    def flush(self):
        """
        Flush flags to the configuration object
        Prepend is used so to allow supplied by
        (downstream/distro/builder) waf caller flags
        to override the upstream flags in wscript.
        """
        for key, val in self.flags.items():
            self.conf.env.prepend_value(key, val)

    def add(self, key, val):
        """
        :param key: Set to add flags to. 'CPPFLAGS', 'CFLAGS', 'CXXFLAGS' or 'LINKFLAGS'
        :param val: string or list of strings
        """
        flags = self.flags[key]
        if isinstance(val, list):
	    #flags.extend(val)
            for x in val:
                if not isinstance(x, str):
                    raise Exception("value must be string or list of strings. ", type(x))
                flags.append(x)
        elif isinstance(val, str):
            flags.append(val)
        else:
            raise Exception("value must be string or list of strings")

    def add_cpp(self, value):
        """
        Add flag or list of flags to CPPFLAGS
        :param value: string or list of strings
        """
        self.add('CPPFLAGS', value)

    def add_c(self, value):
        """
        Add flag or list of flags to CFLAGS
        :param value: string or list of strings
        """
        self.add('CFLAGS', value)

    def add_cxx(self, value):
        """
        Add flag or list of flags to CXXFLAGS
        :param value: string or list of strings
        """
        self.add('CXXFLAGS', value)

    def add_candcxx(self, value):
        """
        Add flag or list of flags to CFLAGS and CXXFLAGS
        :param value: string or list of strings
        """
        self.add_c(value)
        self.add_cxx(value)

    def add_link(self, value):
        """
        Add flag or list of flags to LINKFLAGS
        :param value: string or list of strings
        """
        self.add('LINKFLAGS', value)

def configure(conf):
    conf.load('compiler_cxx')

    conf.check_cfg(
        package = 'fltk-2.0',
        mandatory = True,
        args = '--cflags --libs')

    conf.check_cfg(
        package = 'jack',
        mandatory = True,
        args = '--cflags --libs')

    conf.check_cfg(
        package = 'lash-1.0',
        mandatory = True,
        args = '--cflags --libs')

    flags = WafToolchainFlags(conf)

    #flags.add_c(['-Wall', '-Wextra'])
    flags.add_cxx(['--std=gnu++03'])

    conf.load('autooptions')

    #conf.env['LIB_PTHREAD'] = ['pthread']
    #conf.env['LIB_DL'] = ['dl']
    #conf.env['LIB_RT'] = ['rt']
    #conf.env['LIB_M'] = ['m']
    #conf.env['LIB_STDC++'] = ['stdc++']
    conf.env['EPICHORD_VERSION'] = VERSION

    conf.env['BINDIR'] = conf.env['PREFIX'] + '/bin'

    if Options.options.libdir:
        conf.env['LIBDIR'] = Options.options.libdir
    else:
        conf.env['LIBDIR'] = conf.env['PREFIX'] + '/lib64'

    if Options.options.pkgconfigdir:
        conf.env['PKGCONFDIR'] = Options.options.pkgconfigdir
    else:
        conf.env['PKGCONFDIR'] = conf.env['LIBDIR'] + '/pkgconfig'

    conf.define('EPICHORD_VERSION', conf.env['EPICHORD_VERSION'])
    conf.define('ROOT_DATA_DIR', os.path.normpath(os.path.join(conf.env['PREFIX'], 'share', APPNAME)) + "/")
    conf.write_config_header('config.h', remove=False)

    flags.flush()

    print()
    version_msg = APPNAME + "-" + VERSION
    if os.access('version.h', os.R_OK):
        data = open('version.h').read()
        m = re.match(r'^#define GIT_VERSION "([^"]*)"$', data)
        if m != None:
            version_msg += " exported from " + m.group(1)
    elif os.access('.git', os.R_OK):
        version_msg += " git revision will be checked and eventually updated during build"
    print(version_msg)

    conf.msg('Install prefix', conf.env['PREFIX'], color='CYAN')
    conf.msg('Library directory', conf.all_envs['']['LIBDIR'], color='CYAN')

    tool_flags = [
        ('C++ compiler flags',   ['CXXFLAGS', 'CPPFLAGS']),
        ('Linker flags',       ['LINKFLAGS', 'LDFLAGS'])
    ]
    for name, vars in tool_flags:
        flags = []
        for var in vars:
            flags += conf.all_envs[''][var]
        conf.msg(name, repr(flags), color='NORMAL')

    #conf.summarize_auto_options()

def git_ver(self):
    bld = self.generator.bld
    header = self.outputs[0].abspath()
    if os.access('./version.h', os.R_OK):
        header = os.path.join(os.getcwd(), out, "version.h")
        shutil.copy('./version.h', header)
        data = open(header).read()
        m = re.match(r'^#define GIT_VERSION "([^"]*)"$', data)
        if m != None:
            self.ver = m.group(1)
            Logs.pprint('BLUE', "tarball from git revision " + self.ver)
        else:
            self.ver = "tarball"
        return

    if bld.srcnode.find_node('.git'):
        self.ver = bld.cmd_and_log("LANG= git rev-parse HEAD", quiet=Context.BOTH).splitlines()[0]
        if bld.cmd_and_log("LANG= git diff-index --name-only HEAD", quiet=Context.BOTH).splitlines():
            self.ver += "-dirty"

        Logs.pprint('BLUE', "git revision " + self.ver)
    else:
        self.ver = "unknown"

    fi = open(header, 'w')
    fi.write('#define GIT_VERSION "%s"\n' % self.ver)
    fi.close()

def build(bld):
    bld(rule=git_ver, target='version.h', update_outputs=True, always=True, ext_out=['.h'])

    prog = bld(features=['cxx', 'cxxprogram'], includes = [bld.path.get_bld(), "./src"])
    prog.uselib = 'JACK FLTK-2.0 LASH-1.0'
    prog.target = 'epichord'
    for source in [
            'main.cpp',
            'seq.cpp',
            'jack.cpp',
            'ui.cpp',
            'pianoroll.cpp',
            'trackselect.cpp',
            'eventedit.cpp',
            'timeline.cpp',
            'sampleview.cpp',
            'trackinfo.cpp',
            'arranger.cpp',
            'keyboard.cpp',
            'trackmodule.cpp',
            'util.cpp',
            'midi.cpp',
            'uihelper.cpp',
            'saveload.cpp',
            'metronome.cpp',
            'eventmenu.cpp',
            'theme.cpp',
            'dragbar.cpp',
    ]:
        prog.source.append(os.path.join("src", source))

    bld.install_files(os.path.normpath(os.path.join(bld.env['PREFIX'], 'share', APPNAME, "gfx")), [
        "gfx/color.gif",
        "gfx/conf.gif",
        "gfx/edit.gif",
        "gfx/file.gif",
        "gfx/fork.gif",
        "gfx/hand.gif",
        "gfx/help.gif",
        "gfx/join.gif",
        "gfx/loop.gif",
        "gfx/q0.gif",
        "gfx/q128.gif",
        "gfx/q16.gif",
        "gfx/q32.gif",
        "gfx/q4.gif",
        "gfx/q64.gif",
        "gfx/q8.gif",
        "gfx/scope.gif",
        "gfx/split.gif"])

    bld.install_files(os.path.normpath(os.path.join(bld.env['PREFIX'], 'share', APPNAME, "doc")), [
        "doc/README",
        "doc/color.txt",
        "doc/manual.txt",
        "doc/controls.txt",
        "doc/guide.txt",
        "doc/midi.txt",
        "doc/license.txt"])
