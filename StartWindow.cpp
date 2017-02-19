#include "std_lib_facilities_4.h"
#include "Simple_window.h"
#include "Graph.h"
#include "Window.h"
#include "StartWindow.h"

//-------------------------------------------------------------------------

// Constructors for Class/Struct

Start_window::Start_window(Point xy, int w, int h, const string& title):
    Graph_lib::Window(xy,w,h,title),
    next1_button(Point(x_max()-100,y_max()-100),85,85,"Next", [](Address,Address pw){reference_to<Start_window>(pw).next1();}),
    next2_button(Point(x_max()-100,y_max()-100),85,85,"Next", [](Address,Address pw){reference_to<Start_window>(pw).next2();}),
    D2_button(Point(x_max()/2-20,100),85,40,"2 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D2();}),
    D3_button(Point(x_max()/2-20,150),85,40,"3 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D3();}),
    D4_button(Point(x_max()/2-20,200),85,40,"4 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D4();}),
    D5_button(Point(x_max()/2-20,250),85,40,"5 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D5();}),
    D6_button(Point(x_max()/2-20,300),85,40,"6 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D6();}),
    D7_button(Point(x_max()/2-20,350),85,40,"7 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D7();}),
    D8_button(Point(x_max()/2-20,400),85,40,"8 Hard", [](Address,Address pw){reference_to<Start_window>(pw).D8();}),
    North_button(Point(x_max()-105,5),50,50,"", [](Address,Address pw){reference_to<Start_window>(pw).North();}),
    South_button(Point(x_max()-105,105),50,50,"", [](Address,Address pw){reference_to<Start_window>(pw).South();}),
    West_button(Point(x_max()-155,55),50,50,"", [](Address,Address pw){reference_to<Start_window>(pw).West();}),
    East_button(Point(x_max()-55,55),50,50,"", [](Address,Address pw){reference_to<Start_window>(pw).East();}),
    initial_ibox(Point(x_max()/2-30,75),50,50,"Your Initials:"),
    Score_1(Point(x_max()/2-80,200),150,40,"1)"),
    Score_2(Point(x_max()/2-80,250),150,40,"2)"),
    Score_3(Point(x_max()/2-80,300),150,40,"3)"),
    Score_4(Point(x_max()/2-80,350),150,40,"4)"),
    Score_5(Point(x_max()/2-80,400),150,40,"5)"),
    high_scores(Point(x_max()/2-105,175), "HIGH SCORES"),
    start_screen(Point(0,0),"Splash.jpg"),
    instructions(Point(0,0),"Storyline.jpg"),
    next_button(Point(x_max()-100,y_max()-100),"Button.jpg"),
    DPad(Point(x_max()-155,5),"DPad.jpg"),
    quit_button(Point(x_max()/2-75,y_max()/2+20),100,60,"QUIT", [](Address,Address pw){reference_to<Start_window>(pw).quit();}),
    play_again_button(Point(x_max()/2+75,y_max()/2+20),100,60,"PLAY AGAIN", [](Address,Address pw){reference_to<Start_window>(pw).play_again();}),
    timer_box(Point(x_max()/2-20,20),50,30,"Seconds Left:"),
    HeliumGrids(Point(40,175),"HeliumGrids.jpg"),
    LithiumGrids(Point(40,175),"LithiumGrids.jpg"),
    BerylliumGrids(Point(40,175),"BerylliumGrids.jpg"),
    BoronGrids(Point(40,175),"BoronGrids.jpg"),
    CarbonGrids(Point(40,175),"CarbonGrids.jpg"),
    NitrogenGrids(Point(40,175),"NitrogenGrids.jpg"),
    OxygenGrids(Point(40,175),"OxygenGrids.jpg"),
    current_score(Point(40,20),70,30,"Score"),
    move_box(Point(200,20),50,30,"Moves"),
    hint_box(Point(40,70),50,30,"Hint"),
    hint_button(Point(100,70),50,30,"Hint", [](Address,Address pw){reference_to<Start_window>(pw).hint_help();}),
    button_pushed(false)
{
    attach(start_screen);
    attach(next_button);
    attach(next1_button);
    high_scores.set_font_size(30);
    high_scores.set_color(Color::blue);
}

Score::Score(string n, double s)
    :initials{n}, scores{s} {}


//-------------------------------------------------------------------------

// Operator Overloads

istream& operator>>(istream& input_score, Score& s){
    input_score >> s.initials >> s.scores;
    return input_score;
}

ostream & operator<<(ostream& output_score, Score& s){
    return output_score << s.initials << " " << s.scores << endl;
}

// Used to sort the scores
bool operator<(const Score& p1, const Score& p2){
    return (p1.scores < p2.scores);
}

//-------------------------------------------------------------------------

// Call Back Functions

void Start_window::cb_select_electron1(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron1();
}

void Start_window::cb_select_electron2(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron2();
}

void Start_window::cb_select_electron3(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron3();
}

void Start_window::cb_select_electron4(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron4();
}

void Start_window::cb_select_electron5(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron5();
}

void Start_window::cb_select_electron6(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron6();
}

void Start_window::cb_select_electron7(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron7();
}

void Start_window::cb_select_electron8(Address,Address pw) {
    reference_to<Start_window>(pw).select_electron8();
}

//-------------------------------------------------------------------------

// Define wait for button

bool Start_window::wait_for_button(){
    show();
    button_pushed = false;
#if 1
    while (!button_pushed) Fl::wait();
    Fl::redraw();
#else
    Fl::run(); 
#endif
    return button_pushed;
}

//-------------------------------------------------------------------------

// Declarations/Definitions for variables in global scope

vector<Electron> calc_elec;

vector<Score> all_information; //Vector that contains scores of everyone

auto player_score {0};  //Final Score of Current Player and use of "auto"

int total_moves {0}; // Keeps track of total electron moves

int end_num {0}; // Goes to final screen when end_num = 1

int degree_moved {0}; // Keeps track of how many degrees to move

Score Current_player;

int tick_count {0}; // Keeps track of number of seconds

int num_ticks {0};  // Determines how many seconds to start the clock at

//-------------------------------------------------------------------------

//Functions

// Create Timer
void Start_window::put_timer(){
    timer_box.put(to_string(num_ticks));
    redraw();
}

void Start_window::cb_timer(Address pw){
    ++tick_count;
    --num_ticks;
    reference_to<Start_window>(pw).put_timer();
    if(tick_count < calc_elec.size()*30+1){
        Fl::repeat_timeout(1.0,cb_timer, pw);
    }
    if(num_ticks == 0) {
        reference_to<Start_window>(pw).actions_end();
    }
}

void Start_window::timer(){
    Fl::add_timeout(1.0, cb_timer, this);
}

// Create a string of scores with initials
string create_string(vector<Score>& all_scores, int slot){
    ostringstream os;
    os <<setw(10) <<all_scores[slot].initials << setw(10) << all_scores[slot].scores;
    return os.str();
}

// Put all of the scores from the file into a vector
void read_score_to_game(vector<Score>& all_scores, const string& iname){
    ifstream ist {iname};
    if(!ist) error("Can't open input file ", iname);
    for(Score player; ist >> player;){
        all_scores.push_back(player);
    }
    ist.close();
}

// Write Player's Score to the file for storage
void write_score_to_file(Score p1,double final_score ,vector<Score>& all_scores, const string& oname){
    p1.scores = final_score;
    ofstream ost {oname};
    if(!ost) error("Can't open output file ", oname);
    all_scores.push_back(p1);
    for(auto i: all_scores){   // Range Based For Loop and "auto"
        ost << i << "\n";
    }
    ost.close();
}

//distance calculations
double calc_dist(Electron s1, Electron s2, double radius) {
    return radius*acos( sin(s1.latitude*M_PI/180)*sin(s2.latitude*M_PI/180)+
    cos(s1.latitude*M_PI/180)*cos(s2.latitude*M_PI/180)*cos(abs(s1.longitude-s2.longitude)*M_PI/180));
}

//distance calculations for all objects
double shortest_distance(vector<Electron> v) {
    vector<double> values;
    for (int i=0; i<v.size(); ++i) {
        for (int j=i+1; j<v.size(); ++j) {
            values.push_back(calc_dist(v[i],v[j],4000));
        }
    }
    sort(values.begin(), values.end());
    return values[0];
}

//initializes start spots
void random_start(vector<Electron>& v) {
    srand(time(NULL));
    for (Electron& i: v) {  // use of range for loop
        int rnum=rand();
        int plong=rand()%181;
        int plat=rand()%91;
        i.longitude=pow(-1,rnum)*plong;//180+-
        i.latitude=pow(-1,rnum)*plat;//90+- 
    }
}

//keeps objects on map
void bound_check(Electron& e) {
    if(e.latitude>90) {
        e.latitude=180-e.latitude;
        e.longitude+=180;
    }
    else if(e.latitude<-90) {
        e.latitude=-180-e.latitude;
        e.longitude+=180;
    }
    if(e.longitude>180) {
        e.longitude-=360;
    }
    else if(e.longitude<-180) {
        e.longitude+=360;
    }
}

//tells object the distance to move on map
int x_dist_move (int n,  Electron e) {
    return 2*(e.longitude-n);
}

int y_dist_move (int n, Electron e) {
    return 2*(n-e.latitude);
}

//places object in correct initial spot
int x_convert (Electron e) {
    return 390+2*e.longitude;
}

int y_convert (Electron e) {
    return 345-2*e.latitude;
}

//each hint_vect_ adds the shortest distance after a move in named direction (N,E,S,W) to a vector 
void hint_vect_e(vector<Electron> e, vector<double>& vv,int n){
    vector<Electron> bb8;
    bb8=e;
    for (int i=0; i<e.size();++i) {
        bb8[i].longitude+=n;
        bound_check(bb8[i]);
        vv.push_back(shortest_distance(bb8));
        bb8[i].longitude=e[i].longitude;
    }
}

void hint_vect_w(vector<Electron> e, vector<double>& vv,int n) {
    vector<Electron> bb8;
    bb8=e;
    for (int i=0; i<e.size();++i) {
        bb8[i].longitude-=n;
        bound_check(bb8[i]);
        vv.push_back(shortest_distance(bb8));
        bb8[i].longitude=e[i].longitude;
    }
}

void hint_vect_n(vector<Electron> e, vector<double>& vv,int n) {
    vector<Electron> bb8;
    bb8=e;
    for (int i=0; i<e.size();++i) {
        bb8[i].latitude+=n;
        bound_check(bb8[i]);
        vv.push_back(shortest_distance(bb8));
        bb8[i].latitude=e[i].latitude;
    }
}

void hint_vect_s(vector<Electron> e, vector<double>& vv,int n) {
    vector<Electron> bb8;
    bb8=e;
    for (int i=0; i<e.size();++i) {
        bb8[i].latitude-=n;
        bound_check(bb8[i]);
        vv.push_back(shortest_distance(bb8));
        bb8[i].latitude=e[i].latitude;
    }
}

//function collects all the vectors from the directions into one vector
void hint_vect(vector<Electron> eei, vector<double>& vvi,int nni) {
    hint_vect_e(eei,vvi,nni);
    hint_vect_w(eei,vvi,nni);
    hint_vect_n(eei,vvi,nni);
    hint_vect_s(eei,vvi,nni);
}

//function detrmines which move was best by position in vector and displays it
void Start_window::hint_help() {
    vector<double> v (0);
    hint_vect(calc_elec,v,degree_moved);
    vector<double> vect;
    vect=v;
    char ch;
    bool valfond=true;
    sort(vect.begin(), vect.end());
    for (int i=0; i<v.size() && valfond; ++i) {
        if (v[i]==vect[vect.size()-1]) {
            if(i/calc_elec.size()<1) {ch='E';}
            else if(i/calc_elec.size()>=1 && i/calc_elec.size()<2) {ch='W';}
            else if(i/calc_elec.size()>=2 && i/calc_elec.size()<3) {ch='N';}
            else if(i/calc_elec.size()>=3) {ch='S';}
            ostringstream sout;
            sout<<""<<i%calc_elec.size()+1<<" * "<<ch;
            string ss=sout.str();
            hint_box.put(ss);
            valfond=false;
        }
    }   
}

// Actions to be completed on second next button click
void Start_window::actions_2(){
    detach(next1_button);
    detach(instructions);
    attach(initial_ibox);
    attach(next2_button);
    attach(high_scores);
    attach(Score_1);
    attach(Score_2);
    attach(Score_3);
    attach(Score_4);
    attach(Score_5);
    redraw();
}

// Actions to be completed on third next button click
void Start_window::actions_3(){
    detach(initial_ibox);
    detach(next2_button);
    detach(high_scores);
    detach(Score_1);
    detach(Score_2);
    detach(Score_3);
    detach(Score_4);
    detach(Score_5);
    attach(D2_button);
    attach(D3_button);
    attach(D4_button);
    attach(D5_button);
    attach(D6_button);
    attach(D7_button);
    attach(D8_button);
    detach(next_button);
}

//for reading out score and moves left
void Start_window::score_move_output() {
    ostringstream sout,s2out;
    sout<<calc_elec.size()*shortest_distance(calc_elec);
    s2out<<50-total_moves;
    string ss=sout.str();
    string ss2=s2out.str();
    current_score.put(ss);
    move_box.put(ss2);
}

// Actions to be completed when difficulty button is clicked
void Start_window::actions_general_menu(){
    detach(D2_button);
    detach(D3_button);
    detach(D4_button);
    detach(D5_button);
    detach(D6_button);
    detach(D7_button);
    detach(D8_button);
    attach(North_button);
    attach(South_button);
    attach(West_button);
    attach(East_button);
    attach(DPad);
    attach(current_score);
    attach(move_box);
    attach(hint_box);
    attach(hint_button);
    for(int i = 0;i < electron_v.size();++i) attach(electron_v[i]);
    for(int i = 0;i < electron_image.size();++i) attach(electron_image[i]);
    attach(timer_box);
    timer();
    score_move_output();
}

// Detach these items in the actions end function
void Start_window::detach_items(){
    detach(North_button);
    detach(South_button);
    detach(West_button);
    detach(East_button);
    detach(DPad);
    detach(HeliumGrids);
    detach(LithiumGrids);
    detach(BerylliumGrids);
    detach(BoronGrids);
    detach(CarbonGrids);
    detach(NitrogenGrids);
    detach(OxygenGrids);
    detach(timer_box);
    detach(move_box);
    detach(hint_box);
    detach(hint_button);
}

// Actions to be completed when game is over (time is out or out of moves)
void Start_window::actions_end(){
    detach_items();
    current_score.move(360,200);
    for(int i = 0;i < electron_v.size();++i) detach(electron_v[i]);
    for(int i = 0;i < electron_image.size();++i) detach(electron_image[i]);
    attach(quit_button);
    attach(play_again_button);
    player_score = calc_elec.size()*shortest_distance(calc_elec);
    write_score_to_file(Current_player,player_score,all_information,"all_scores.txt");
    Fl::remove_timeout(cb_timer);
}

// Put top 5 scores from vector into outboxes
void Start_window::read_out_scores() {
    if (all_information.size()==0){}//if file is less than 5, reads out as
    if (all_information.size()>0){// many as possible
        Score_1.put(create_string(all_information,all_information.size()-1));
    }
    if (all_information.size()>1){
        Score_2.put(create_string(all_information,all_information.size()-2));
    }
    if (all_information.size()>2){
        Score_3.put(create_string(all_information,all_information.size()-3));
    }
    if (all_information.size()>3){
        Score_4.put(create_string(all_information,all_information.size()-4));
    }
    if (all_information.size()>4){
        Score_5.put(create_string(all_information,all_information.size()-5));
    }
}

//creates buttons that represent electrons
void Start_window::create_electrons(int i) {
    if (i>1) {
        electron_v.push_back(new Button(Point{x_convert(calc_elec[0]),y_convert(calc_elec[0])},20,20,"",cb_select_electron1));
        electron_v.push_back(new Button(Point{x_convert(calc_elec[1]),y_convert(calc_elec[1])},20,20,"",cb_select_electron2));
        }
    if (i>2) {electron_v.push_back(new Button(Point{x_convert(calc_elec[2]),y_convert(calc_elec[2])},20,20,"",cb_select_electron3));}
    if (i>3) {electron_v.push_back(new Button(Point{x_convert(calc_elec[3]),y_convert(calc_elec[3])},20,20,"",cb_select_electron4));}
    if (i>4) {electron_v.push_back(new Button(Point{x_convert(calc_elec[4]),y_convert(calc_elec[4])},20,20,"",cb_select_electron5));}
    if (i>5) {electron_v.push_back(new Button(Point{x_convert(calc_elec[5]),y_convert(calc_elec[5])},20,20,"",cb_select_electron6));}
    if (i>6) {electron_v.push_back(new Button(Point{x_convert(calc_elec[6]),y_convert(calc_elec[6])},20,20,"",cb_select_electron7));}
    if (i>7) {electron_v.push_back(new Button(Point{x_convert(calc_elec[7]),y_convert(calc_elec[7])},20,20,"",cb_select_electron8));}
}

//creates images for the buttons that represent electrons
void Start_window::create_electrons_jpg(int i) {
    if (i>1) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[0]),y_convert(calc_elec[0])},"Electron1.jpg"));
        electron_image.push_back(new Image(Point{x_convert(calc_elec[1]),y_convert(calc_elec[1])},"Electron2.jpg"));}
    if (i>2) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[2]),y_convert(calc_elec[2])},"Electron3.jpg"));}
    if (i>3) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[3]),y_convert(calc_elec[3])},"Electron4.jpg"));}
    if (i>4) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[4]),y_convert(calc_elec[4])},"Electron5.jpg"));}
    if (i>5) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[5]),y_convert(calc_elec[5])},"Electron6.jpg"));}
    if (i>6) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[6]),y_convert(calc_elec[6])},"Electron7.jpg"));}
    if (i>7) {
        electron_image.push_back(new Image(Point{x_convert(calc_elec[7]),y_convert(calc_elec[7])},"Electron8.jpg"));}
}

//makes the 10 steps 20,10,5,1 degrees
void calculate_moves(){
    if (total_moves < 10) degree_moved = 20;
    if (total_moves >= 10 && total_moves < 20) degree_moved = 15;
    if (total_moves >= 20 && total_moves < 30) degree_moved = 10;
    if (total_moves >= 30 && total_moves < 40) degree_moved = 5;
    if (total_moves >= 40 && total_moves < 50) degree_moved = 1;
    if (total_moves == 49) end_num = 1;
}

// Reset appropriate variables for play again
void reset_variables(){
    tick_count =0;
    num_ticks = 0;
    total_moves = 0;
    end_num = 0;
    degree_moved = 0;
    all_information.clear();
}

//-------------------------------------------------------------------------

//Functions used by Call back functions

// First and Second button call back functions
void Start_window::next1(){
    ++button_count;
    if(button_count == 1){
        detach(start_screen);
        attach(instructions);
        attach(next_button);
        redraw();
    } else if(button_count == 2){
        actions_2();
        read_score_to_game(all_information,"all_scores.txt");
        sort(all_information.begin(), all_information.end());
        read_out_scores();
    }
}

// Third button call back function
void Start_window::next2(){
    string player_initial = initial_ibox.get_string();
    Current_player.initials = player_initial; // Initialize Current Player Initials
    actions_3();
}

//select_electron 1-8 are the button functions for the electrons 
//tells which electron has been selected
void Start_window::select_electron1(){
    move_electron=0;
}

void Start_window::select_electron2(){
    move_electron=1;
}

void Start_window::select_electron3(){
    move_electron=2;
}

void Start_window::select_electron4(){
    move_electron=3;
}

void Start_window::select_electron5(){
    move_electron=4;
}

void Start_window::select_electron6(){
    move_electron=5;
}

void Start_window::select_electron7(){
    move_electron=6;
}

void Start_window::select_electron8(){
    move_electron=7;
}

//D2-8 are difficulty level functions
void Start_window::D2(){
    num_ticks = 2*30+1;
    calc_elec.resize(2);
    random_start(calc_elec);
    create_electrons(2);
    create_electrons_jpg(2);
    attach(HeliumGrids);
    actions_general_menu();
}

void Start_window::D3(){
    num_ticks = 3*30+1;
    calc_elec.resize(3);
    random_start(calc_elec);
    create_electrons(3);
    create_electrons_jpg(3);
    attach(LithiumGrids);
    actions_general_menu();
}

void Start_window::D4(){
    num_ticks = 4*30+1;
    calc_elec.resize(4);
    random_start(calc_elec);
    create_electrons(4);
    create_electrons_jpg(4);
    attach(BerylliumGrids);
    actions_general_menu();
}

void Start_window::D5(){
    num_ticks = 5*30+1;
    calc_elec.resize(5);
    random_start(calc_elec);
    create_electrons(5);
    create_electrons_jpg(5);
    attach(BoronGrids);
    actions_general_menu();
}

void Start_window::D6(){
    num_ticks = 6*30+1;
    calc_elec.resize(6);
    random_start(calc_elec);
    create_electrons(6);
    create_electrons_jpg(6);
    attach(CarbonGrids);
    actions_general_menu();
}

void Start_window::D7(){
    num_ticks = 7*30+1;
    calc_elec.resize(7);
    random_start(calc_elec);
    create_electrons(7);
    create_electrons_jpg(7);
    attach(NitrogenGrids);
    actions_general_menu();
}

void Start_window::D8(){
    num_ticks = 8*30+1;
    calc_elec.resize(8);
    random_start(calc_elec);
    create_electrons(8);
    create_electrons_jpg(8);
    attach(OxygenGrids);
    actions_general_menu();
}

//movement operations for the electrons
void Start_window::North(){
    calculate_moves();
    ++total_moves;
    int a=calc_elec[move_electron].longitude;
    int b=calc_elec[move_electron].latitude;
    calc_elec[move_electron].latitude+=degree_moved;
    bound_check(calc_elec[move_electron]);
    electron_v[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    electron_image[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    score_move_output();
    hint_box.put("");
    if(end_num == 1) actions_end();
}

void Start_window::South(){
    calculate_moves();
    ++total_moves;
    int a=calc_elec[move_electron].longitude;
    int b=calc_elec[move_electron].latitude;
    calc_elec[move_electron].latitude-=degree_moved;
    bound_check(calc_elec[move_electron]);
    electron_v[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    electron_image[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    score_move_output();
    hint_box.put("");
    if(end_num == 1) actions_end();
}

void Start_window::West(){
    calculate_moves();
    ++total_moves;
    int a=calc_elec[move_electron].longitude;
    int b=calc_elec[move_electron].latitude;
    calc_elec[move_electron].longitude-=degree_moved;
    bound_check(calc_elec[move_electron]);
    electron_v[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    electron_image[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    score_move_output();
    hint_box.put("");
    if(end_num == 1) actions_end();
}

void Start_window::East(){
    calculate_moves();
    ++total_moves;
    int a=calc_elec[move_electron].longitude;
    int b=calc_elec[move_electron].latitude;
    calc_elec[move_electron].longitude+=degree_moved;
    bound_check(calc_elec[move_electron]);
    electron_v[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    electron_image[move_electron].move(x_dist_move(a,calc_elec[move_electron]),y_dist_move(b,calc_elec[move_electron]));
    score_move_output();
    hint_box.put("");
    if(end_num == 1) actions_end();
}

//end game options
void Start_window::quit(){
    button_pushed = true;
    exit(0);
}

void Start_window::play_again(){
    hide();
    reset_variables();
    Start_window win{Point(100,100),800,600,"Electron Boogaloo"};
    win.wait_for_button();
}
