#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"


struct Start_window : Graph_lib::Window {
    Start_window(Point xy, int w, int h, const string& title);
    int button_count {0}; // Keeps track of how many times the first button is clicked
    int move_electron {0}; // Keeps track of which electron is clicked to move

private:
    // Declaration of Buttons
    Button next1_button;
    Button next2_button;
    Button D2_button;
    Button D3_button;
    Button D4_button;
    Button D5_button;
    Button D6_button;
    Button D7_button;
    Button D8_button;
    Button North_button;
    Button South_button;
    Button West_button;
    Button East_button;
    Button quit_button;
    Button play_again_button;
    Button hint_button;
    
    Vector_ref<Button> electron_v;  // Vector that contains Buttons for electrons
    Vector_ref<Image> electron_image; // Vector that contains Images for electrons

    Text high_scores; // "High Scores" text

    // Declaration of Images
    Image start_screen;
    Image instructions;
    Image next_button;
    Image DPad;
    Image HeliumGrids;
    Image LithiumGrids;
    Image BerylliumGrids;
    Image BoronGrids;
    Image CarbonGrids;
    Image NitrogenGrids;
    Image OxygenGrids;

    In_box initial_ibox; // Box declared to input initials

    // Declaration of Out Boxes
    Out_box Score_1;
    Out_box Score_2;
    Out_box Score_3;
    Out_box Score_4;
    Out_box Score_5;
    Out_box timer_box;
    Out_box current_score;
    Out_box move_box;
    Out_box hint_box;

    // Used for play again
    bool wait_for_button();
    bool button_pushed;
    
    // Functions used by called back functions
    void next1();
    void next2();
    void D2();
    void D3();
    void D4();
    void D5();
    void D6();
    void D7();
    void D8();
    void select_electron1();
    void select_electron2();
    void select_electron3();
    void select_electron4();
    void select_electron5();
    void select_electron6();
    void select_electron7();
    void select_electron8();
    void quit();
    void play_again();
    void put_timer();
    void North();
    void South();
    void West();
    void East();
    
    // Call back functions
    static void cb_select_electron1(Address, Address);
    static void cb_select_electron2(Address, Address);
    static void cb_select_electron3(Address, Address);
    static void cb_select_electron4(Address, Address);
    static void cb_select_electron5(Address, Address);
    static void cb_select_electron6(Address, Address);
    static void cb_select_electron7(Address, Address);
    static void cb_select_electron8(Address, Address);
    static void cb_timer(Address);

    // Declaration of functions used throughout program
    void actions_2();
    void actions_3();
    void actions_general_menu();
    void actions_end();
    void read_out_scores();
    void create_electrons(int i);
    void create_electrons_jpg(int i);
    void timer();
    void score_move_output();
    void hint_help();
    void detach_items();

};

// Class containing information for each player
class Score{
public:
    string initials;
    double scores;

    Score() {};
    Score(string n, double s);
};

// Struct containing information for each electron
struct Electron {
    double longitude;
    double latitude;
};
