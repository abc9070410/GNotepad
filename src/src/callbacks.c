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

  gtk_window_set_title (GTK_WINDOW (data->window), utf8("新文件"));

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
// 儲存檔案  
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
// 離開 
{
  gtk_widget_destroy(data->window);
}


void
on________t_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// 剪下 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard; 
  
  // 若GDK_NONE不行就換GDK_SELECTION_PRIMARY 
  clipboard = gtk_clipboard_get( GDK_NONE ); // 取得反白選取的部份 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // 取得整個編輯緩衝區 
  
  gtk_text_buffer_cut_clipboard (buffer, clipboard, TRUE); // 將反白選取的部份剪下到剪貼簿 

}


void
on________c_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// 複製 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard;
  
  clipboard = gtk_clipboard_get( GDK_NONE ); // 取得反白選取的部份 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // 取得整個編輯緩衝區 
  
  gtk_text_buffer_copy_clipboard (buffer, clipboard); // 將反白選取的部份複製到剪貼簿 

}


void
on________p_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// 貼上 
{
  GtkTextBuffer *buffer;
  GtkClipboard *clipboard;
  
  clipboard = gtk_clipboard_get( GDK_NONE ); // 取得反白選取的部份 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // 取得整個編輯緩衝區 
  
  gtk_text_buffer_paste_clipboard (buffer, clipboard, NULL, TRUE); // 將剪貼簿的內容貼到指定區域 

}


void
on________d_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data)
// 刪除 
{
  GtkTextBuffer *buffer;
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); // 取得整個編輯緩衝區 
  
  gtk_text_buffer_delete_selection (buffer, TRUE, TRUE); // 將反白選取的部份刪除 
}


void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        AD         data)
// 開啟關於dialog 
{
  GtkWidget *dialog1_information = create_dialog1_information ();
  gtk_widget_show (dialog1_information);
  gtk_dialog_run (GTK_DIALOG (dialog1_information));
  gtk_widget_destroy (dialog1_information);

}


void
on_mainfile1_activate                  (GtkMenuItem     *menuitem,
                                        AD         data)
// 開啟main.c 
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
// 開啟interface.c
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
// 開啟callbacks.c
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
// 離開 
{

}
  
void 
on_search_button_clicked (GtkWidget *search_button, AD data)
// 搜尋按鈕的功能 
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
// 銷毀search dialog 
{
  gtk_widget_destroy (search_dialog);
}
 

 
void
on_search_okbutton_clicked (GtkWidget *search_button, AD data)
// 搜尋按鈕的功能，可連續搜尋 
{
  const gchar *text = "e";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  GtkTextMark *last_pos;
  int result = 0 ; 
  gboolean found = FALSE;  
    
  data->searchWord = gtk_entry_get_text (GTK_ENTRY (data->entry)); // 取得輸入欄的字串 
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); 
  
  last_pos = gtk_text_buffer_get_mark (buffer, "last_pos"); // 查看有無last_pos的mark 
  if (last_pos == NULL)
    gtk_text_buffer_get_start_iter (buffer, &iter); // 若無，就從頭搜尋 
  else
    gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos); // 若有，就從最後一個last_pos的後面開始搜尋 
  
  found = find (GTK_TEXT_VIEW (data->textview), data->searchWord, &iter);
  
  if (!found)
    gtk_text_buffer_delete_mark (buffer, last_pos); // 搜尋到最後可回到起點重新搜尋 
}
 

void
on_next_button_clicked (GtkWidget *next_button, GdkEventKey *event, AD data)
// 按下『F3』找下一個符合字串 
// ＊因為無法把searchWord正確傳遞，所以無法正常使用此函式。 
{
  const gchar *text;
  GtkTextBuffer *buffer;
  GtkTextMark *last_pos;
  GtkTextIter iter;
   
  if( !strcmp( gdk_keyval_name( event->keyval ), "F3" ) ) {
         
    
    text = "e" ; // 預設搜尋e 
    //text = data->searchWord;
    
    buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview));

    last_pos = gtk_text_buffer_get_mark (buffer, "last_pos");
    if (last_pos == NULL)
      gtk_text_buffer_get_start_iter (buffer, &iter); // 若無，就從頭搜尋 
    else
      gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos);
    //find (GTK_TEXT_VIEW (data->textview), text, &iter);
    
    find (GTK_TEXT_VIEW (data->textview), text, &iter);
  
  }
}


void 
on_replace_button_clicked (GtkWidget *replace_button, AD data)
// 搜尋按鈕的功能 
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
// 銷毀replace dialog 
{
  gtk_widget_destroy (replace_dialog);
}

 
void
on_replace_okbutton_clicked (GtkWidget *replace_button, AD data)
// 取代按鈕的功能，可連續取代 
{
  const gchar *text = "e";
  GtkTextBuffer *buffer;
  GtkTextIter iter;
  GtkTextMark *last_pos;
  int result = 0 ; 
    
  data->searchWord = gtk_entry_get_text (GTK_ENTRY (data->entry)); // 取得輸入欄的字串 
  data->replaceWord = gtk_entry_get_text (GTK_ENTRY (data->entry2)); // 取得輸入欄的字串
  
  buffer = gtk_text_view_get_buffer (GTK_TEXT_VIEW (data->textview)); 
  
  last_pos = gtk_text_buffer_get_mark (buffer, "last_pos"); // 查看有無last_pos的mark 
  if (last_pos == NULL)
    gtk_text_buffer_get_start_iter (buffer, &iter); // 若無，就從頭搜尋 
  else
    gtk_text_buffer_get_iter_at_mark (buffer, &iter, last_pos); // 若有，就從最後一個last_pos的後面開始搜尋 
  
  replace (GTK_TEXT_VIEW (data->textview), data->searchWord, data->replaceWord, &iter);
  
}

