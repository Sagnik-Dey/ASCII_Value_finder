// Header Files
#include <gtk/gtk.h>

// *********** STRUCTURES ************
// structure for the data
typedef struct dataStruct
{
    GtkWidget *widget1;
    GtkWidget *widget2;
} datas;

// ********** FUNCTIONS *************
// function for finding ascii value
void findAsciiValue(GtkWidget *widget, datas *data)
{
    // *********** VARIABLES ************
    int asciiValue = 0;

    // get active string from the combobox
    gchar *character = gtk_combo_box_text_get_active_text(GTK_COMBO_BOX(data->widget1));
    // if the text is equals to NULL
    if (character==NULL)
    {
        // setting an error text in the entry
        gtk_entry_set_text(GTK_ENTRY(data->widget2), "Choose a character to find its ASCII Value");
    }
    // else
    else
    {
        // looping through the string
        for (int i = 0; i < 1; i++)
        {
            // ascii value of the character
            asciiValue = (int) character[i];
            // typecasting the integer to string
            gchar *value = g_strdup_printf("%d", asciiValue);
            // setting the ascii value in the output entry
            gtk_entry_set_text(GTK_ENTRY(data->widget2), value);        
        }
    }
    // free the character
    g_free(character);
    
}

// Main Function
int main(int argc, char const *argv[])
{
    // *********** CONSTANTS ***********
    const char windowTitle[] = "ASCII Finder";
    const int windowWidth = 400;
    const int windowHeight = 400;

    // ********** GTK VARIABLES **********
    GtkWidget *window;

    GtkWidget *headingLabel;
    GtkWidget *label1;
    GtkWidget *label2;

    GtkWidget *combo;

    GtkWidget *findButton;

    GtkWidget *outputEntry;

    GtkWidget *vbox;
    GtkWidget *hbox;
    GtkWidget *hbox2;
    GtkWidget *hbox3;

    // gtk init
    gtk_init(&argc, &argv);

    // Window
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), windowTitle);
    gtk_window_set_default_size(GTK_WINDOW(window), windowWidth, windowHeight);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);

    // labels
    gchar *headingStr = "<span size = 'larger'><b> ASCII Value Finder </b></span>";
    headingLabel = gtk_label_new(NULL);
    gtk_label_set_markup(GTK_LABEL(headingLabel), headingStr);
    label1 = gtk_label_new("Choose the Character :- ");
    label2 = gtk_label_new("ASCII Value of the character is :- ");

    // combobox
    combo = gtk_combo_box_text_new();
    gchar *characterArray = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    for (int i = 0; i <= 26*2 ; i++)
    {
        gchar *str = g_strdup_printf("%c", characterArray[i]);
        gtk_combo_box_text_append_text(GTK_COMBO_BOX(combo),str);
    }

    // buttons
    findButton = gtk_button_new_with_label("Find the ASCII Value");
    gtk_widget_set_tooltip_text(GTK_WIDGET(findButton), "Find the ASCII Value of the chosen character");

    // entries
    outputEntry = gtk_entry_new();
    gtk_entry_set_placeholder_text(GTK_ENTRY(outputEntry), "The ASCII Value of the chosen character will be shown here");
    
    // vbox
    vbox = gtk_vbox_new(FALSE, 10);

    // hbox
    hbox = gtk_hbox_new(FALSE, 10);
    hbox2 = gtk_hbox_new(FALSE, 10);
    hbox3 = gtk_hbox_new(FALSE, 10);

    // struct initialization
    datas data;
    data.widget1 = combo;
    data.widget2 = outputEntry;

    // packing widgets
    gtk_box_pack_start(GTK_BOX(vbox), headingLabel, FALSE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), label1, FALSE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox), combo, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), hbox, TRUE, TRUE, 20);
    gtk_box_pack_start(GTK_BOX(hbox2), findButton, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), hbox2, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), label2, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(hbox3), outputEntry, TRUE, TRUE, 10);
    gtk_box_pack_start(GTK_BOX(vbox), hbox3, TRUE, TRUE, 10);

    // container
    gtk_container_add(GTK_CONTAINER(window), vbox);

    // Quit function
    g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

    // Finding the value
    g_signal_connect(G_OBJECT(findButton), "clicked", G_CALLBACK(findAsciiValue), &data);

    // Showing All the Widgets
    gtk_widget_show_all(window);

    // Mainloop
    gtk_main();

    return 0;
}
