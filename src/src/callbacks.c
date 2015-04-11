#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif 
 
#include <gtk/gtk.h>

#include "support.h"
#include "callbacks.h"
#include "interface.h"

const gchar *gSearchWord ;
 
  
void
on________n_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
{
  GtkTextBuffer *buffer;
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview));
  gtk_text_buffer_set_text (buffer, "", 0);

  gtk_window_set_title (GTK_WINDOW (data->window), utf8("�s���"));

}


void
on________o_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
{
  //GtkWidget *dialog = create_file_chooser_open_dialog (GTK_WINDOW(window));
   
   
  GtkWidget *dialog = gtk_file_chooser_dialog_new ("Open File",
			                            GTK_WINDOW(data->window),
                                        GTK_FILE_CHOOSER_ACTION_OPEN,
                                        GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
                                        GTK_STOCK_OPEN, GTK_RESPONSE_ACCEPT, 
                                        NULL);
  
  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;

    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    open_file (filename, GTK_TEXT_VIEW (data->textview));
    
    gtk_window_set_title (GTK_WINDOW (data->window), filename);
    g_free (filename);
  }
  
  gtk_widget_destroy (dialog);

}


void
on________s_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// �x�s�ɮ�  
{
  GtkWidget *dialog;

  dialog = gtk_file_chooser_dialog_new ("Save File",
	 			                                GTK_WINDOW(data->window),
	 			                                GTK_FILE_CHOOSER_ACTION_SAVE,
	 			                                GTK_STOCK_CANCEL, GTK_RESPONSE_CANCEL,
				                                GTK_STOCK_SAVE, GTK_RESPONSE_ACCEPT,
				                                NULL);

  gtk_file_chooser_set_do_overwrite_confirmation (GTK_FILE_CHOOSER (dialog), TRUE);
  
  if (0)//user_edited_a_new_document)
  {
    gtk_file_chooser_set_current_folder (GTK_FILE_CHOOSER (dialog), "NEW.txt");//default_folder_for_saving);
    gtk_file_chooser_set_current_name (GTK_FILE_CHOOSER (dialog), "Untitled document");
  }
  else
    gtk_file_chooser_set_filename (GTK_FILE_CHOOSER (dialog), "OLD.txt");//filename_for_existing_document);


  if (gtk_dialog_run (GTK_DIALOG (dialog)) == GTK_RESPONSE_ACCEPT)
  {
    char *filename;

    filename = gtk_file_chooser_get_filename (GTK_FILE_CHOOSER (dialog));
    save_to_file (filename, GTK_TEXT_VIEW (data->textview));
    gtk_window_set_title (GTK_WINDOW (data->window), filename);
    g_free (filename);
  }
  
  gtk_widget_destroy (dialog);

}


void
on______________a_1_activate           (GtkMenuItem     *menuitem,
                                        AD         data)
{

}


void
on________q_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// ���} 
{
  gtk_widget_destroy(data->window);
}


void
on________t_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// �ŤU 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard; 
  
  // �YGDK_NONE����N��GDK_SELECTION_PRIMARY 
  clipboard = gtk_clipboard_get( GDK_NONE ); // ���o�ϥտ�������� 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // ���o��ӽs��w�İ� 
  
  gtk_text_buffer_cut_clipboard (buffer, clipboard, TRUE); // �N�ϥտ���������ŤU��ŶKï 

}


void
on________c_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// �ƻs 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard;
  
  clipboard = gtk_clipboard_get( GDK_NONE ); // ���o�ϥտ�������� 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // ���o��ӽs��w�İ� 
  
  gtk_text_buffer_copy_clipboard (buffer, clipboard); // �N�ϥտ���������ƻs��ŶKï 

}


void
on________p_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// �K�W 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard;
  
  clipboard = gtk_clipboard_get( GDK_NONE ); // ���o�ϥտ�������� 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // ���o��ӽs��w�İ� 
  
  gtk_text_buffer_paste_clipboard (buffer, clipboard, NULL, TRUE); // �N�ŶKï�����e�K����w�ϰ� 

}


void
on________d_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// �R�� 
{
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // ���o��ӽs��w�İ� 
  
  gtk_text_buffer_delete_selection (buffer, TRUE, TRUE); // �N�ϥտ���������R�� 
}


void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        AD         data)
// �}������dialog 
{
  GtkWidget *dialog1_information = create_dialog1_information ();
  gtk_widget_show (dialog1_information);
  gtk_dialog_run (GTK_DIALOG (dialog1_information));
  gtk_widget_destroy (dialog1_information);

}


void
on_mainfile1_activate                  (GtkMenuItem     *menuitem,
                                        AD         data)
// �}��main.c 
{
    char *filename; 

    filename = "..\\src\\main.c";
    open_file (filename, GTK_TEXT_VIEW (data->textview));
    
    gtk_window_set_title (GTK_WINDOW (data->window), filename);
    g_free (filename);
}

 
void
on_interfacefile1_activate             (GtkMenuItem     *menuitem,
                                        AD         data)
// �}��interface.c
{ 
    char *filename;

    filename = "..\\src\\support.c";
    open_file (filename, GTK_TEXT_VIEW (data->textview));
    
    gtk_window_set_title (GTK_WINDOW (data->window), filename);
    g_free (filename);

}


void
on_callbacksfile1_activate             (GtkMenuItem     *menuitem,
                                        AD         data)
// �}��callbacks.c
{
    char *filename;

    filename = "..\\src\\callbacks.c";
    open_file (filename, GTK_TEXT_VIEW (data->textview));
    
    gtk_window_set_title (GTK_WINDOW (data->window), filename);
    g_free (filename);

}

 
void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        AD         data)
// ���} 
{

}
  
void 
on_search_button_clicked (GtkWidget *search_button, AD data)
// �j�M���s���\�� 
{
  const gchar *text = "";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  int result = 0 ;
    
  GtkWidget *search_dialog = create_search_dialog (data);
  gtk_widget_show (search_dialog); 
  
  //result = gtk_dialog_run (GTK_DIALOG (search_dialog));
  
   
  //gtk_widget_destroy (search_dialog);
}
 
void
on_search_cancelbutton_clicked (GtkWidget *button, gpointer search_dialog)
// �P��search dialog 
{
  gtk_widget_destroy (search_dialog);
}
 

 
void
on_search_okbutton_clicked (GtkWidget *search_button, AD data)
// �j�M���s���\��A�i�s��j�M 
{
  const gchar *text = "e";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  GtkTextMark *last_pos;
  int result = 0 ; 
  gboolean found = FALSE;  
    
  data->searchWord = gtk_entry_get_text (GTK_ENTRY (data->entry)); // ���o��J�檺�r�� 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); 
  
  last_pos = gtk_text_buffer_get_mark (buffer, "last_pos"); // �d�ݦ��Llast_pos��mark 
  if (last_pos == NULL)
    gtk_text_buffer_get_start_iter (buffer, &iter); // �Y�L�A�N�q�Y�j�M 
  else
    gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos); // �Y���A�N�q�̫�@��last_pos���᭱�}�l�j�M 
  
  found = find (GTK_TEXT_VIEW (data->textview), data->searchWord, &iter);
  
  if (!found)
    gtk_text_buffer_delete_mark (buffer, last_pos); // �j�M��̫�i�^��_�I���s�j�M 
}
 

void
on_next_button_clicked (GtkWidget *next_button, GdkEventKey *event, AD data)
// ���U�yF3�z��U�@�ӲŦX�r�� 
// ���]���L�k��searchWord���T�ǻ��A�ҥH�L�k���`�ϥΦ��禡�C 
{
  const gchar *text;
  GtkTextBuffer *buffer;
  GtkTextMark *last_pos;
  GtkTextIter iter;
   
  if( !strcmp( gdk_keyval_name( event->keyval ), "F3" ) ) {
         
    
    text = "e" ; // �w�]�j�Me 
    //text = data->searchWord;
    
    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview));

    last_pos = gtk_text_buffer_get_mark (buffer, "last_pos");
    if (last_pos == NULL)
      gtk_text_buffer_get_start_iter (buffer, &iter); // �Y�L�A�N�q�Y�j�M 
    else
      gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos);
    //find (GTK_TEXT_VIEW (data->textview), text, &iter);
    
    find (GTK_TEXT_VIEW (data->textview), text, &iter);
  
  }
}


void 
on_replace_button_clicked (GtkWidget *replace_button, AD data)
// �j�M���s���\�� 
{
  const gchar *text = "";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  int result = 0 ;
    
  GtkWidget *replace_dialog = create_replace_dialog (data);
  gtk_widget_show (replace_dialog); 
  //result = gtk_dialog_run (GTK_DIALOG (search_dialog));
   
  //gtk_widget_destroy (search_dialog);
}
 
void
on_replace_cancelbutton_clicked (GtkWidget *button, gpointer replace_dialog)
// �P��replace dialog 
{
  gtk_widget_destroy (replace_dialog);
}

 
void
on_replace_okbutton_clicked (GtkWidget *replace_button, AD data)
// ���N���s���\��A�i�s����N 
{
  const gchar *text = "e";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  GtkTextMark *last_pos;
  int result = 0 ; 
    
  data->searchWord = gtk_entry_get_text (GTK_ENTRY (data->entry)); // ���o��J�檺�r�� 
  data->replaceWord = gtk_entry_get_text (GTK_ENTRY (data->entry2)); // ���o��J�檺�r��
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); 
  
  last_pos = gtk_text_buffer_get_mark (buffer, "last_pos"); // �d�ݦ��Llast_pos��mark 
  if (last_pos == NULL)
    gtk_text_buffer_get_start_iter (buffer, &iter); // �Y�L�A�N�q�Y�j�M 
  else
    gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos); // �Y���A�N�q�̫�@��last_pos���᭱�}�l�j�M 
  
  replace (GTK_TEXT_VIEW (data->textview), data->searchWord, data->replaceWord, &iter);
  
}

