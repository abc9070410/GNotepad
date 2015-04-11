#include <gtk/gtk.h>
 
struct AllData { // 視窗裡面的所有資料 
  GtkWidget *window;
  GtkWidget *textview;
  GtkWidget *statusbar;
  GtkWidget *entry;
  GtkWidget *entry2;
  const gchar *searchWord;
  const gchar *replaceWord;
}; 
typedef struct AllData *AD;  


void
on________n_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________o_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________s_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on______________a_1_activate           (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________q_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________t_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________c_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________p_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on________d_1_activate                 (GtkMenuItem     *menuitem,
                                        AD         data);

void
on_about1_activate                     (GtkMenuItem     *menuitem,
                                        AD         data);

void
on_mainfile1_activate                  (GtkMenuItem     *menuitem,
                                        AD         data);

void
on_interfacefile1_activate             (GtkMenuItem     *menuitem,
                                        AD         data);

void
on_callbacksfile1_activate             (GtkMenuItem     *menuitem,
                                        AD         data);

void
on_quit1_activate                      (GtkMenuItem     *menuitem,
                                        AD         data);


void
on_search_button_clicked (GtkWidget *search_button, AD data); // 按下搜尋按鈕跳出dialog 
void
on_next_button_clicked (GtkWidget *next_button, GdkEventKey *event, AD data); // 找下一個符合字串 

void
on_search_okbutton_clicked (GtkWidget *search_button, AD data); // dialog上的ok按鈕 
void
on_search_cancelbutton_clicked (GtkWidget *search_button, gpointer search_dialog); // dialog上的cancel按鈕 




void
on_replace_button_clicked (GtkWidget *replace_button, AD data); // 按下搜尋按鈕跳出dialog 
void
on_replace_okbutton_clicked (GtkWidget *replace_button, AD data); // dialog上的ok按鈕 
void
on_replace_cancelbutton_clicked (GtkWidget *replace_button, gpointer search_dialog); // dialog上的cancel按鈕 
