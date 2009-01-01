// generated by Fast Light User Interface Designer (fluid) version 2.1000

#include "ui.h"
/*
   Epichord - a midi sequencer
   Copyright (C) 2008  Evan Rinehart

   This program is free software; you can redistribute it and/or
   modify it under the terms of the GNU General Public License
   as published by the Free Software Foundation; either version 2
   of the License, or (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to

   The Free Software Foundation, Inc.
   51 Franklin Street, Fifth Floor
   Boston, MA  02110-1301, USA
*/
#include <fltk/events.h>
#include <fltk/file_chooser.h>
#include "backend.h"
#include "util.h"
#include "uihelper.h"
#include "config.h"
extern UI* ui;

inline void UI::cb_main_window_i(fltk::Window* o, void*) {
  config_window->hide();
  help_window->hide();
  action_window->hide();
  scope_window->hide();
  o->hide();
  
  save_config();
}
void UI::cb_main_window(fltk::Window* o, void* v) {
  ((UI*)(o->user_data()))->cb_main_window_i(o,v);
}

inline void UI::cb__i(fltk::Button*, void*) {
  ui->track_info->toggle_controls();
}
void UI::cb_(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb__i(o,v);
}

inline void UI::cb_event_menu_button_i(fltk::Button* o, void*) {
  if(o->state()==0){
    ui->event_menu->hide();
    ui->event_edit->show();
  }
  else{
    ui->event_edit->hide();
    ui->event_edit->recount_has();
    ui->event_menu->show();
  }
;}
void UI::cb_event_menu_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_event_menu_button_i(o,v);
}

inline void UI::cb_L_i(fltk::Button* o, void*) {
  ui->event_edit->label_flag = o->state();
  ui->event_edit->redraw();
}
void UI::cb_L(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_L_i(o,v);
}

inline void UI::cb_C_i(fltk::Button*, void*) {
  ui->event_edit->clear_events();
}
void UI::cb_C(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_C_i(o,v);
}

inline void UI::cb_X_i(fltk::Button*, void*) {
  ui->event_edit->clear_non_note_events();
}
void UI::cb_X(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_X_i(o,v);
}

inline void UI::cb_Z_i(fltk::Button*, void*) {
  ui->event_edit->clear_all_events();
}
void UI::cb_Z(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->parent()->user_data()))->cb_Z_i(o,v);
}

inline void UI::cb_1_i(fltk::Button*, void*) {
  show_song_edit();
}
void UI::cb_1(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_1_i(o,v);
}

inline void UI::cb_play_button_i(fltk::Button*, void*) {
  press_play();
}
void UI::cb_play_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_play_button_i(o,v);
}

inline void UI::cb_stop_button_i(fltk::Button*, void*) {
  press_stop();
}
void UI::cb_stop_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_stop_button_i(o,v);
}

inline void UI::cb_record_button_i(fltk::Button*, void*) {
  toggle_backend_recording();
}
void UI::cb_record_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_record_button_i(o,v);
}

inline void UI::cb_qbutton4_i(fltk::Button*, void*) {
  set_quant(4);
}
void UI::cb_qbutton4(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton4_i(o,v);
}

inline void UI::cb_qbutton8_i(fltk::Button*, void*) {
  set_quant(8);
}
void UI::cb_qbutton8(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton8_i(o,v);
}

inline void UI::cb_qbutton16_i(fltk::Button*, void*) {
  set_quant(16);
}
void UI::cb_qbutton16(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton16_i(o,v);
}

inline void UI::cb_qbutton32_i(fltk::Button*, void*) {
  set_quant(32);
}
void UI::cb_qbutton32(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton32_i(o,v);
}

inline void UI::cb_qbutton64_i(fltk::Button*, void*) {
  set_quant(64);
}
void UI::cb_qbutton64(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton64_i(o,v);
}

inline void UI::cb_qbutton128_i(fltk::Button*, void*) {
  set_quant(128);
}
void UI::cb_qbutton128(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton128_i(o,v);
}

inline void UI::cb_qbutton0_i(fltk::Button*, void*) {
  set_quant(0);
}
void UI::cb_qbutton0(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_qbutton0_i(o,v);
}

inline void UI::cb_tool_button_i(fltk::Button*, void*) {
  toggle_tool();
}
void UI::cb_tool_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_tool_button_i(o,v);
}

inline void UI::cb_color_toggle_i(fltk::Button* o, void*) {
  arranger->color_flag = o->state();
}
void UI::cb_color_toggle(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_color_toggle_i(o,v);
}

inline void UI::cb_loop_toggle_i(fltk::Button*, void*) {
  toggle_loop();
}
void UI::cb_loop_toggle(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_loop_toggle_i(o,v);
}

inline void UI::cb_config_button_i(fltk::Button*, void*) {
  ui->config_window->show();
}
void UI::cb_config_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_config_button_i(o,v);
}

inline void UI::cb_scope_button_i(fltk::Button*, void*) {
  ui->scope_window->show();
}
void UI::cb_scope_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_scope_button_i(o,v);
}

inline void UI::cb_file_button_i(fltk::Button*, void*) {
  //load(fltk::file_chooser("save file",NULL,"~"));
  ui->action_window->show();
}
void UI::cb_file_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_file_button_i(o,v);
}

inline void UI::cb_help_button_i(fltk::Button*, void*) {
  help_window->show();
}
void UI::cb_help_button(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->parent()->user_data()))->cb_help_button_i(o,v);
}

inline void UI::cb_beats_per_measure_i(fltk::ValueInput* o, void*) {
  if(o->value() > o->maximum())
    o->value(o->maximum());
  if(o->value() < o->minimum())
    o->value(o->minimum());
  set_beats_per_measure((int)o->value());
}
void UI::cb_beats_per_measure(fltk::ValueInput* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_beats_per_measure_i(o,v);
}

inline void UI::cb_measures_per_phrase_i(fltk::ValueInput* o, void*) {
  if(o->value() > o->maximum())
    o->value(o->maximum());
  if(o->value() < o->minimum())
    o->value(o->minimum());
  set_measures_per_phrase((int)o->value());
}
void UI::cb_measures_per_phrase(fltk::ValueInput* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_measures_per_phrase_i(o,v);
}

inline void UI::cb_bpm_wheel_i(fltk::ThumbWheel* o, void*) {
  set_bpm((int)o->value());
  ui->bpm_output->value(o->value());
}
void UI::cb_bpm_wheel(fltk::ThumbWheel* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_bpm_wheel_i(o,v);
}

inline void UI::cb_measures_until_record_i(fltk::ValueInput* o, void*) {
  if(o->value() > o->maximum())
    o->value(o->maximum());
  if(o->value() < o->minimum())
    o->value(o->minimum());
  set_measures_until_record((int)o->value());
}
void UI::cb_measures_until_record(fltk::ValueInput* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_measures_until_record_i(o,v);
}

inline void UI::cb_check_alwayscopy_i(fltk::CheckButton* o, void*) {
  set_alwayscopy(o->value());
}
void UI::cb_check_alwayscopy(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_alwayscopy_i(o,v);
}

inline void UI::cb_check_autotrackname_i(fltk::CheckButton* o, void*) {
  set_autotrackname(o->value());
}
void UI::cb_check_autotrackname(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_autotrackname_i(o,v);
}

inline void UI::cb_check_passthru_i(fltk::CheckButton* o, void*) {
  set_passthru(o->value());
}
void UI::cb_check_passthru(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_passthru_i(o,v);
}

inline void UI::cb_check_playinsert_i(fltk::CheckButton* o, void*) {
  set_playinsert(o->value());
}
void UI::cb_check_playinsert(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_playinsert_i(o,v);
}

inline void UI::cb_check_recordonchan_i(fltk::CheckButton* o, void*) {
  set_recordonchan(o->value());
}
void UI::cb_check_recordonchan(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_recordonchan_i(o,v);
}

inline void UI::cb_check_playmove_i(fltk::CheckButton* o, void*) {
  set_playmove(o->value());
}
void UI::cb_check_playmove(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_playmove_i(o,v);
}

inline void UI::cb_check_follow_i(fltk::CheckButton* o, void*) {
  set_follow(o->value());
}
void UI::cb_check_follow(fltk::CheckButton* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_check_follow_i(o,v);
}

inline void UI::cb_merge_i(fltk::Item*, void*) {
  set_recordmode(0);
}
void UI::cb_merge(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_merge_i(o,v);
}

inline void UI::cb_overwrite_i(fltk::Item*, void*) {
  set_recordmode(1);
}
void UI::cb_overwrite(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_overwrite_i(o,v);
}

inline void UI::cb_layer_i(fltk::Item*, void*) {
  set_recordmode(2);
}
void UI::cb_layer(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_layer_i(o,v);
}

inline void UI::cb_do_i(fltk::Item*, void*) {
  set_robmode(0);
}
void UI::cb_do(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_do_i(o,v);
}

inline void UI::cb_new_i(fltk::Item*, void*) {
  set_robmode(1);
}
void UI::cb_new(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_new_i(o,v);
}

inline void UI::cb_extend_i(fltk::Item*, void*) {
  set_robmode(2);
}
void UI::cb_extend(fltk::Item* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->parent()->user_data()))->cb_extend_i(o,v);
}

inline void UI::cb_default_velocity_i(fltk::ValueInput* o, void*) {
  if(o->value() > o->maximum())
    o->value(o->maximum());
  if(o->value() < o->minimum())
    o->value(o->minimum());
  set_defaultvelocity(o->value());
}
void UI::cb_default_velocity(fltk::ValueInput* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_default_velocity_i(o,v);
}

inline void UI::cb_kg_l10_i(KeyGrabber*, void*) {
  ;
}
void UI::cb_kg_l10(KeyGrabber* o, void* v) {
  ((UI*)(o->parent()->parent()->parent()->user_data()))->cb_kg_l10_i(o,v);
}

inline void UI::cb_new1_i(fltk::Button*, void*) {
  clear();
  init_seq();
  track_info->update();
  action_window->hide();
}
void UI::cb_new1(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->user_data()))->cb_new1_i(o,v);
}

inline void UI::cb_save_i(fltk::Button*, void*) {
  action_window->hide();
  save();
}
void UI::cb_save(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->user_data()))->cb_save_i(o,v);
}

inline void UI::cb_save1_i(fltk::Button*, void*) {
  action_window->hide();
  save(fltk::file_chooser("save file",NULL,get_last_dir()));
}
void UI::cb_save1(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->user_data()))->cb_save1_i(o,v);
}

inline void UI::cb_load_i(fltk::Button*, void*) {
  action_window->hide();
  load(fltk::file_chooser("open file",NULL,get_last_dir()));
}
void UI::cb_load(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->user_data()))->cb_load_i(o,v);
}

inline void UI::cb_export_i(fltk::Button*, void*) {
  action_window->hide();
  savesmf(fltk::file_chooser("export file",NULL,get_last_dir()));
}
void UI::cb_export(fltk::Button* o, void* v) {
  ((UI*)(o->parent()->user_data()))->cb_export_i(o,v);
}

UI::UI() {
  fltk::Window* w;
   {fltk::Window* o = main_window = new fltk::Window(640, 480, "Epichord");
    o->shortcut(0xff1b);
    o->callback((fltk::Callback*)cb_main_window, (void*)(this));
    o->begin();
     {fltk::Group* o = new fltk::Group(0, 0, 640, 445);
      o->begin();
       {fltk::Group* o = song_edit = new fltk::Group(0, 0, 640, 445);
        o->begin();
         {fltk::Group* o = new fltk::Group(0, 0, 255, 445);
          o->set_vertical();
          o->box(fltk::FLAT_BOX);
          o->begin();
           {TrackInfo* o = track_info = new TrackInfo(0, 15, 255, 415, "track info");
            o->set_vertical();
            fltk::Group::current()->resizable(o);
          }
           {fltk::Button* o = new fltk::Button(0, 0, 255, 15, "@+");
            o->callback((fltk::Callback*)cb_);
          }
          o->end();
        }
         {fltk::Group* o = new fltk::Group(255, 0, 385, 15);
          o->begin();
           {Timeline* o = song_timeline = new Timeline(0, 0, 370, 15, "timeline");
            fltk::Group::current()->resizable(o);
            o->scale=16;
            o->label_scale=4;
          }
          o->end();
        }
         {CustomScroll* o = song_scroll = new CustomScroll(255, 15, 385, 430);
          o->set_vertical();
          o->begin();
           {Arranger* o = arranger = new Arranger(0, 0, 245, 220, "arranger");
            o->box(fltk::FLAT_BOX);
            o->resize(1000,30*16);
          }
          o->end();
          o->type(fltk::ScrollGroup::BOTH_ALWAYS);
          fltk::Group::current()->resizable(o);
        }
        o->end();
      }
       {fltk::Group* o = pattern_edit = new fltk::Group(0, 0, 640, 445);
        o->hide();
        o->begin();
         {fltk::Group* o = new fltk::Group(45, 0, 595, 445);
          o->begin();
           {fltk::Group* o = new fltk::Group(0, 0, 595, 15);
            o->begin();
             {Timeline* o = pattern_timeline = new Timeline(0, 0, 580, 15, "timeline");
              o->box(fltk::FLAT_BOX);
              fltk::Group::current()->resizable(o);
              o->edit_flag = 1;
            }
            o->end();
          }
           {fltk::ScrollGroup* o = pattern_scroll = new fltk::ScrollGroup(0, 15, 595, 355);
            o->box(fltk::FLAT_BOX);
            o->shortcut(0xff1b);
            o->when(fltk::WHEN_CHANGED);
            o->begin();
             {PianoRoll* o = piano_roll = new PianoRoll(0, 0, 595, 355, "pianoroll");
              o->box(fltk::FLAT_BOX);
              fltk::Group::current()->resizable(o);
              o->resize(960,900);
            }
            o->end();
            o->type(fltk::ScrollGroup::BOTH_ALWAYS);
            fltk::Group::current()->resizable(o);
          }
           {fltk::Group* o = new fltk::Group(0, 370, 595, 75);
            o->begin();
             {EventEdit* o = event_edit = new EventEdit(0, 0, 580, 75, "event editor");
              o->box(fltk::FLAT_BOX);
            }
             {EventMenu* o = event_menu = new EventMenu(0, 0, 580, 75);
              o->box(fltk::FLAT_BOX);
              o->hide();
            }
             {fltk::Button* o = event_menu_button = new fltk::Button(580, 0, 15, 15, "E");
              o->callback((fltk::Callback*)cb_event_menu_button);
              o->tooltip("pick event type");
              o->type(fltk::Button::TOGGLE);
            }
             {fltk::Button* o = new fltk::Button(580, 15, 15, 15, "L");
              o->callback((fltk::Callback*)cb_L);
              o->tooltip("toggle event value labels");
              o->type(fltk::Button::TOGGLE);
            }
             {fltk::Button* o = new fltk::Button(580, 30, 15, 15, "C");
              o->callback((fltk::Callback*)cb_C);
              o->tooltip("clear these events");
            }
             {fltk::Button* o = new fltk::Button(580, 45, 15, 15, "X");
              o->callback((fltk::Callback*)cb_X);
              o->tooltip("clear all non note events in pattern");
            }
             {fltk::Button* o = new fltk::Button(580, 60, 15, 15, "Z");
              o->labelcolor((fltk::Color)0xff000000);
              o->callback((fltk::Callback*)cb_Z);
              o->tooltip("clear everything");
            }
            o->end();
          }
          o->end();
          fltk::Group::current()->resizable(o);
        }
         {fltk::Group* o = new fltk::Group(0, 0, 45, 445);
          o->begin();
          new fltk::Button(0, 0, 45, 15, "@+");
           {fltk::Group* o = new fltk::Group(0, 15, 45, 340);
            o->set_vertical();
            o->begin();
             {TrackSelect* o = track_select = new TrackSelect(0, 35, 45, 305, "track picker");
              o->set_vertical();
            }
             {SampleView* o = sample_view = new SampleView(0, 35, 45, 305, "sample names");
              o->set_vertical();
            }
             {Keyboard* o = keyboard = new Keyboard(0, 0, 45, 340, "keyboard");
              o->set_vertical();
            }
            o->end();
            fltk::Group::current()->resizable(o);
          }
           {fltk::Button* o = new fltk::Button(0, 370, 45, 75, "@<-");
            o->set_vertical();
            o->callback((fltk::Callback*)cb_1);
          }
          o->end();
        }
        o->end();
      }
      o->end();
      fltk::Group::current()->resizable(o);
    }
     {fltk::Group* o = new fltk::Group(0, 445, 640, 35);
      o->box(fltk::UP_BOX);
      o->begin();
       {fltk::Button* o = play_button = new fltk::Button(5, 5, 25, 25, "@>");
        o->labelcolor((fltk::Color)0x800000);
        o->callback((fltk::Callback*)cb_play_button);
      }
       {fltk::Button* o = stop_button = new fltk::Button(35, 5, 25, 25, "@square");
        o->labelcolor((fltk::Color)0x800000);
        o->callback((fltk::Callback*)cb_stop_button);
      }
       {fltk::Button* o = record_button = new fltk::Button(65, 5, 25, 25, "@circle");
        o->labelcolor((fltk::Color)0xff000000);
        o->callback((fltk::Callback*)cb_record_button);
        o->type(fltk::Button::TOGGLE);
      }
       {Metronome* o = metronome = new Metronome(95, 5, 25, 25, "0");
        o->color((fltk::Color)56);
        o->labelcolor((fltk::Color)0xffffff00);
      }
       {fltk::Group* o = new fltk::Group(200, 0, 20, 35);
        o->set_vertical();
        fltk::Group::current()->resizable(o);
      }
       {fltk::Group* o = pattern_buttons = new fltk::Group(145, 5, 310, 25);
        o->hide();
        o->begin();
         {fltk::Button* o = qbutton4 = new fltk::Button(135, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton4);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = qbutton8 = new fltk::Button(160, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton8);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = qbutton16 = new fltk::Button(185, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton16);
          o->type(fltk::Button::TOGGLE);
          o->state(1);
        }
         {fltk::Button* o = qbutton32 = new fltk::Button(210, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton32);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = qbutton64 = new fltk::Button(235, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton64);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = qbutton128 = new fltk::Button(260, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton128);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = qbutton0 = new fltk::Button(285, 0, 25, 25);
          o->callback((fltk::Callback*)cb_qbutton0);
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = quant1_button = new fltk::Button(15, 0, 25, 25, "qua");
          o->tooltip("quantize selected notes");
        }
         {fltk::Button* o = quant0_button = new fltk::Button(45, 0, 25, 25, "qu_");
          o->tooltip("quantize length of selected notes");
        }
         {fltk::Button* o = tool_button = new fltk::Button(75, 0, 25, 25, "tool");
          o->callback((fltk::Callback*)cb_tool_button);
        }
        o->end();
      }
       {fltk::Group* o = song_buttons = new fltk::Group(340, 5, 115, 25);
        o->begin();
         {fltk::Button* o = color_toggle = new fltk::Button(0, 0, 25, 25);
          o->callback((fltk::Callback*)cb_color_toggle);
          o->tooltip("color tool");
          o->type(fltk::Button::TOGGLE);
        }
         {fltk::Button* o = unclone_button = new fltk::Button(30, 0, 25, 25, "dclo");
          o->tooltip("unclone selected block");
        }
         {fltk::Button* o = join_button = new fltk::Button(60, 0, 25, 25, "join");
          o->tooltip("join selected blocks");
        }
         {fltk::Button* o = split_button = new fltk::Button(90, 0, 25, 25, "split");
          o->tooltip("split selected block");
        }
        o->end();
      }
       {fltk::Button* o = loop_toggle = new fltk::Button(490, 5, 25, 25);
        o->callback((fltk::Callback*)cb_loop_toggle);
        o->tooltip("toggle looping");
        o->type(fltk::Button::TOGGLE);
      }
       {fltk::Button* o = config_button = new fltk::Button(520, 5, 25, 25, "conf");
        o->callback((fltk::Callback*)cb_config_button);
        o->tooltip("configuration");
      }
       {fltk::Button* o = scope_button = new fltk::Button(550, 5, 25, 25);
        o->callback((fltk::Callback*)cb_scope_button);
        o->tooltip("scope");
      }
       {fltk::Button* o = file_button = new fltk::Button(580, 5, 25, 25);
        o->callback((fltk::Callback*)cb_file_button);
        o->tooltip("disk");
      }
       {fltk::Button* o = help_button = new fltk::Button(610, 5, 25, 25);
        o->callback((fltk::Callback*)cb_help_button);
        o->tooltip("help");
      }
      o->end();
    }
    o->end();
    o->size_range(640,455);
    o->resize(640,455);
  }
   {fltk::Window* o = config_window = new fltk::Window(320, 285, "controls");
    o->shortcut(0xff1b);
    o->user_data((void*)(this));
    o->begin();
     {fltk::TabGroup* o = new fltk::TabGroup(0, 0, 320, 285);
      o->begin();
       {fltk::Group* o = new fltk::Group(145, 15, 170, 265, "options");
        o->begin();
         {fltk::ValueInput* o = beats_per_measure = new fltk::ValueInput(5, 5, 45, 20, "beats per measure");
          o->minimum(1);
          o->maximum(31);
          o->step(1);
          o->value(4);
          o->callback((fltk::Callback*)cb_beats_per_measure);
        }
         {fltk::ValueInput* o = measures_per_phrase = new fltk::ValueInput(5, 30, 45, 20, "measures per phrase");
          o->maximum(128);
          o->step(1);
          o->value(4);
          o->callback((fltk::Callback*)cb_measures_per_phrase);
        }
         {fltk::ValueOutput* o = bpm_output = new fltk::ValueOutput(5, 55, 45, 20, "bpm");
          o->minimum(1);
          o->maximum(1000);
          o->step(1);
          o->value(120);
        }
         {fltk::ThumbWheel* o = bpm_wheel = new fltk::ThumbWheel(55, 55, 105, 20);
          o->minimum(1);
          o->maximum(1000);
          o->step(1);
          o->value(120);
          o->callback((fltk::Callback*)cb_bpm_wheel);
          o->align(fltk::ALIGN_LEFT);
        }
         {fltk::ValueInput* o = measures_until_record = new fltk::ValueInput(5, 80, 45, 20, "measures until record");
          o->maximum(128);
          o->step(1);
          o->value(1);
          o->callback((fltk::Callback*)cb_measures_until_record);
        }
         {fltk::CheckButton* o = check_alwayscopy = new fltk::CheckButton(5, 105, 25, 25, "always hard copy");
          o->callback((fltk::Callback*)cb_check_alwayscopy);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("instead of making a linked clone when you copy a block in the song view.");
        }
         {fltk::CheckButton* o = check_autotrackname = new fltk::CheckButton(145, 105, 25, 25, "auto track name");
          o->callback((fltk::Callback*)cb_check_autotrackname);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Fill in GM instruments for track names when you change the program.");
        }
         {fltk::CheckButton* o = check_passthru = new fltk::CheckButton(5, 130, 25, 26, "record pass-thru");
          o->set_flag(fltk::STATE);
          o->callback((fltk::Callback*)cb_check_passthru);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Echo midi input to midi output.");
        }
         {fltk::CheckButton* o = check_playinsert = new fltk::CheckButton(145, 130, 25, 26, "play note insertion");
          o->set_flag(fltk::STATE);
          o->callback((fltk::Callback*)cb_check_playinsert);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Send midi note on when you create notes.");
        }
         {fltk::CheckButton* o = check_recordonchan = new fltk::CheckButton(5, 155, 25, 25, "record on channel");
          o->callback((fltk::Callback*)cb_check_recordonchan);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Record on first track that matches channel of midi input instead of selected \
track.");
        }
         {fltk::CheckButton* o = check_playmove = new fltk::CheckButton(145, 155, 25, 26, "play note move");
          o->set_flag(fltk::STATE);
          o->callback((fltk::Callback*)cb_check_playmove);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Send midi note on when you move notes.");
        }
         {fltk::CheckButton* o = check_follow = new fltk::CheckButton(5, 179, 25, 26, "follow playback");
          o->set_flag(fltk::STATE);
          o->callback((fltk::Callback*)cb_check_follow);
          o->align(fltk::ALIGN_LEFT);
          o->tooltip("Auto scroll horizontally when play head leaves viewing area.");
        }
         {fltk::Choice* o = menu_recordmode = new fltk::Choice(5, 210, 160, 25, "record mode");
          o->begin();
           {fltk::Item* o = new fltk::Item("merge");
            o->callback((fltk::Callback*)cb_merge);
          }
           {fltk::Item* o = new fltk::Item("overwrite");
            o->callback((fltk::Callback*)cb_overwrite);
          }
           {fltk::Item* o = new fltk::Item("layer");
            o->callback((fltk::Callback*)cb_layer);
          }
          o->end();
        }
         {fltk::Choice* o = menu_rob = new fltk::Choice(5, 240, 160, 25, "record outside block");
          o->begin();
           {fltk::Item* o = new fltk::Item("do nothing");
            o->callback((fltk::Callback*)cb_do);
          }
           {fltk::Item* o = new fltk::Item("new block");
            o->callback((fltk::Callback*)cb_new);
          }
           {fltk::Item* o = new fltk::Item("extend block");
            o->callback((fltk::Callback*)cb_extend);
          }
          o->end();
        }
         {fltk::ValueInput* o = default_velocity = new fltk::ValueInput(120, 180, 45, 20, "default velocity");
          o->maximum(127);
          o->step(1);
          o->value(96);
          o->callback((fltk::Callback*)cb_default_velocity);
        }
        o->end();
      }
       {fltk::Group* o = new fltk::Group(0, 15, 320, 270, "keyboard");
        o->hide();
        o->begin();
         {KeyGrabber* o = kg_l0 = new KeyGrabber(35, 5, 45, 15, "C0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l1 = new KeyGrabber(35, 20, 45, 15, "C#0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l2 = new KeyGrabber(35, 35, 45, 15, "D0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l3 = new KeyGrabber(35, 50, 45, 15, "D#0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l4 = new KeyGrabber(35, 65, 45, 15, "E0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l5 = new KeyGrabber(35, 80, 45, 15, "F0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l6 = new KeyGrabber(35, 95, 45, 15, "F#0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l7 = new KeyGrabber(35, 110, 45, 15, "G0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l8 = new KeyGrabber(35, 125, 45, 15, "G#0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l9 = new KeyGrabber(35, 140, 45, 15, "A0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l10 = new KeyGrabber(35, 155, 45, 15, "A#0");
          o->callback((fltk::Callback*)cb_kg_l10);
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l11 = new KeyGrabber(35, 170, 45, 15, "B0");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l12 = new KeyGrabber(35, 185, 45, 15, "C1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l13 = new KeyGrabber(35, 200, 45, 15, "C#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l14 = new KeyGrabber(35, 215, 45, 15, "D1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l15 = new KeyGrabber(35, 230, 45, 15, "D#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_l16 = new KeyGrabber(35, 245, 45, 15, "E1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u0 = new KeyGrabber(130, 5, 45, 15, "C1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u1 = new KeyGrabber(130, 20, 45, 15, "C#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u2 = new KeyGrabber(130, 35, 45, 15, "D1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u3 = new KeyGrabber(130, 50, 45, 15, "D#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u4 = new KeyGrabber(130, 65, 45, 15, "E1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u5 = new KeyGrabber(130, 80, 45, 15, "F1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u6 = new KeyGrabber(130, 95, 45, 15, "F#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u7 = new KeyGrabber(130, 110, 45, 15, "G1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u8 = new KeyGrabber(130, 125, 45, 15, "G#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u9 = new KeyGrabber(130, 140, 45, 15, "A1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u10 = new KeyGrabber(130, 155, 45, 15, "A#1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u11 = new KeyGrabber(130, 170, 45, 15, "B1");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u12 = new KeyGrabber(130, 185, 45, 15, "C2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u13 = new KeyGrabber(130, 200, 45, 15, "C#2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u14 = new KeyGrabber(130, 215, 45, 15, "D2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u15 = new KeyGrabber(130, 230, 45, 15, "D#2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u16 = new KeyGrabber(130, 245, 45, 15, "E2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u17 = new KeyGrabber(265, 5, 45, 15, "F2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u18 = new KeyGrabber(265, 20, 45, 15, "F#2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u19 = new KeyGrabber(265, 35, 45, 15, "G2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_u20 = new KeyGrabber(265, 50, 45, 15, "G#2");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_zi = new KeyGrabber(265, 65, 45, 15, "zoom in");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_zo = new KeyGrabber(265, 80, 45, 15, "zoom out");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_ou = new KeyGrabber(265, 95, 45, 15, "octave up");
          o->align(fltk::ALIGN_LEFT);
        }
         {KeyGrabber* o = kg_od = new KeyGrabber(265, 110, 45, 15, "octave down");
          o->align(fltk::ALIGN_LEFT);
        }
        o->end();
      }
      o->end();
    }
    o->end();
    o->resizable(o);
  }
   {fltk::Window* o = help_window = new fltk::Window(580, 370, "help");
    o->shortcut(0xff1b);
    o->user_data((void*)(this));
    o->begin();
     {fltk::TabGroup* o = new fltk::TabGroup(0, 0, 580, 370);
      o->begin();
       {fltk::Group* o = new fltk::Group(0, 25, 580, 345, "info");
        o->begin();
        title_text = new fltk::Input(55, 5, 520, 20, "Title");
        author_text = new fltk::Input(55, 30, 520, 20, "Author");
         {fltk::TextEditor* o = info_text = new fltk::TextEditor(5, 55, 570, 285);
          o->textfont(fltk::COURIER);
          fltk::Group::current()->resizable(o);
        }
        o->end();
        fltk::Group::current()->resizable(o);
      }
       {fltk::Group* o = new fltk::Group(0, 25, 580, 345, "controls");
        o->hide();
        o->begin();
         {fltk::TextDisplay* o = new fltk::TextDisplay(5, 5, 570, 335);
          o->textfont(fltk::COURIER);
          fltk::Group::current()->resizable(o);
          load_text(o,ROOT_DATA_DIR"doc/controls.txt");
        }
        o->end();
      }
       {fltk::Group* o = new fltk::Group(0, 25, 580, 345, "guide");
        o->hide();
        o->begin();
         {fltk::TextDisplay* o = new fltk::TextDisplay(5, 5, 570, 335);
          o->textfont(fltk::COURIER);
          fltk::Group::current()->resizable(o);
          load_text(o,ROOT_DATA_DIR"doc/guide.txt");
        }
        o->end();
      }
       {fltk::Group* o = new fltk::Group(0, 25, 580, 345, "license");
        o->hide();
        o->begin();
         {fltk::TextDisplay* o = new fltk::TextDisplay(5, 5, 570, 335);
          o->textfont(fltk::COURIER);
          fltk::Group::current()->resizable(o);
          load_text(o,ROOT_DATA_DIR"doc/license.txt");
        }
        o->end();
      }
       {fltk::Group* o = new fltk::Group(0, 25, 580, 345, "about");
        o->hide();
        o->begin();
         {fltk::TextDisplay* o = new fltk::TextDisplay(5, 5, 570, 335);
          o->textfont(fltk::COURIER);
          fltk::Group::current()->resizable(o);
          load_text(o,ROOT_DATA_DIR"doc/README");
        }
        o->end();
      }
      o->end();
    }
    o->end();
    o->size_range(580,370);
    o->resizable(o);
  }
   {fltk::Window* o = action_window = new fltk::Window(100, 130, "menu");
    o->shortcut(0xff1b);
    o->user_data((void*)(this));
    o->begin();
     {fltk::Button* o = new fltk::Button(5, 5, 90, 20, "new");
      o->callback((fltk::Callback*)cb_new1);
    }
     {fltk::Button* o = new fltk::Button(5, 25, 90, 20, "save");
      o->callback((fltk::Callback*)cb_save);
    }
     {fltk::Button* o = new fltk::Button(5, 45, 90, 20, "save as");
      o->callback((fltk::Callback*)cb_save1);
    }
     {fltk::Button* o = new fltk::Button(5, 65, 90, 20, "load");
      o->callback((fltk::Callback*)cb_load);
    }
    new fltk::Button(5, 85, 90, 20, "import");
     {fltk::Button* o = new fltk::Button(5, 105, 90, 20, "export");
      o->callback((fltk::Callback*)cb_export);
    }
    o->end();
  }
   {fltk::Window* o = scope_window = new fltk::Window(425, 280, "scope");
    w = o;
    o->shortcut(0xff1b);
    o->user_data((void*)(this));
    o->begin();
     {fltk::TextDisplay* o = scope = new fltk::TextDisplay(5, 5, 415, 245);
      o->textfont(fltk::COURIER);
      o->color((fltk::Color)0x280000);
      o->textcolor((fltk::Color)0xff0000);
      o->wrap_mode(1);
    }
     {fltk::Button* o = new fltk::Button(5, 255, 30, 20, "on");
      o->type(fltk::Button::TOGGLE);
    }
    o->end();
    o->resizable(o);
  }
  loop_toggle->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/loop.gif"));
  color_toggle->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/color.gif"));
  scope_button->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/conf.gif"));
  file_button->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/file.gif"));
  help_button->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/help.gif"));
  
  qbutton4->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q4.gif"));
  qbutton8->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q8.gif"));
  qbutton16->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q16.gif"));
  qbutton32->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q32.gif"));
  qbutton64->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q64.gif"));
  qbutton128->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q128.gif"));
  qbutton0->image(fltk::SharedImage::get(ROOT_DATA_DIR"gfx/q0.gif"));
  track_info->set_rec(0);
  start_monitor();
  main_window->show();
}
