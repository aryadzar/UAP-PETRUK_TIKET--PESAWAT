#include <iostream>
#include <unistd.h>   
#include <iomanip>
#include <vector>
#include <SFML/Audio.hpp>
#include <queue>
#include <algorithm>


#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"
#define GRAY "\033[1;30m"
#define BLACK   "\033[30m"   
#define WHITE_BG "\033[47m"     
#define SLEEP_SCREEN 2


using namespace std;
using namespace sf;


void clearScreen();
void utama();
void pauseScreen();


class HeaderFooter {

public:

    void Header();
    void Welcome();
    void to();
    void pesawat();
    void footer();
    void pesawatFooter();
    void kota();
    HeaderFooter();
};

struct JadwalPesawat{
    string namePlane,Departure, arrival, boeing, harga;
    friend ostream& operator<<(ostream& os, const JadwalPesawat& jadwal) {
        os << "|    " << setw(29) << left << jadwal.namePlane << "|";
        os << setw(10) << left << jadwal.boeing << "|";
        os << setw(24) << left << jadwal.Departure << "|";
        os << setw(24) << left << jadwal.arrival << "|\n";
        return os;
    }
};

class FlightDisplay : public HeaderFooter {
    private :
    vector<JadwalPesawat> jadwalBisnis = {
        {"Citilink", "Soekarno Hatta (09:00)", "Sultan Iskandar Muda(11:45)","CI546", "Rp. 3.000.000,00"},
        {"Batik Air", "Soekarno Hatta (14:00)", "Husein Sastranegara(15:00) ","BA483", "Rp. 1.000.000,00"},
        {"Garuda Indonesia", "Soekarno Hatta (16:00)", "Adi Soemarmo(17:20)        ","GA219", "Rp. 1.300.000,00"},
        {"Garuda Indonesia", "Soekarno Hatta (13:00)", "Raden Intan(13:50)         ","GA219", "Rp. 850.000,00"}

    };
    vector<JadwalPesawat> jadwalFirst = {        
        {"Garuda Indonesia", "Soekarno Hatta (13:00)", "Raden Intan(13:50)             ","GA219","Rp. 1.000.000,00"},
        {"Emirates", "Soekarno Hatta (11:00)", "Dubai International Port(01:50)","EM861","Rp. 15.000.000,00"},
        {"Lion Air ", "Soekarno Hatta (07:00)", "Kualanamu(09:50)               ","LN989","Rp. 3.000.000,00"}


    };
    vector<JadwalPesawat> jadwaleconomy = {
        {"Garuda Indonesia", "Soekarno Hatta (13:00)", "Raden Intan(13:50)","GA219","Rp. 500.000,00      "},
        {"Sriwijaya Air", "Soekarno Hatta (12:00)", "Ngurah Rai Bali(16:50)","SR909","Rp. 300.000,00      "},
        {"Lion Air ", "Soekarno Hatta (13:20)", "Kualanamu(15:50)","LR2911","Rp. 1.000.000.000,00"},
        {"Garuda Indonesia", "Soekarno Hatta (13:20)", "Juanda(13:50)","GA515","Rp. 700.000,00      "},
        {"Wings Air", "Soekarno Hatta (17:00)", "Harun Thahir(19:50)","GA219","Rp. 900.000,00      "}
    };
    vector<JadwalPesawat> jadwalPenerbangan1 = {
        {"Garuda Indonesia", "Soekarno Hatta (13:00)", "Raden Intan(13:50)","GA219","Rp. 500.000,00"},
        {"Garuda Indonesia", "Soekarno Hatta (13:20)", "Juanda(13:50)","GA515","Rp. 700.000,00"},
        {"Wings Air", "Soekarno Hatta (17:00)", "Harun Thahir(19:50)","GA219","Rp. 900.000,00"}

    };

    vector <vector<string>> kursifirst = {
        {"A1",  "B1"},
        {"A2",  "B2"},
        {"A3",  "B3"},
        {"A4",  "B4"},
        {"A5",  "B5"}
    };
    vector <vector<string>> kursiekonomi = {
        {"A1","B1", "C1", "D1", "E1", "F1"},
        {"A2","B2", "C2", "D2", "E2", "F2"},
        {"A3","B3", "C4", "D3", "E3", "F3"},
        {"A4","B4", "C3", "D4", "E4", "F4"},
        {"A5","B5", "C5", "D5", "E5", "F5"},
        {"A6","B6", "C6", "D6", "E6", "F6"},
        {"A7","B7", "C7", "D7", "E7", "F7"},
        {"A8","B8", "C8", "D8", "E8", "F8"},
        {"A9","B9", "C9", "D9", "E9", "F9"},
        {"A10","B10", "C10", "D10", "E10", "F10"}

    };
    vector <vector<string>> kursibisnis = {
        {"A1","B1", "C1", "D1"},
        {"A2","B2", "C2", "D2"},
        {"A3","B3", "C3", "D3"},
        {"A4","B4", "C4", "D4"},
        {"A5","B5", "C5", "D5"}
    };

    queue<JadwalPesawat> lepaspes;
    

    JadwalPesawat jad1 =   {"Emirates", "Soekarno Hatta (11:00)", "Dubai International Port(1:50)","EM861",};
    JadwalPesawat jad2 =   {"Sriwijaya Air", "Soekarno Hatta (12:00)", "Ngurah Rai Bali(16:50)        ","SR909"};
    JadwalPesawat jad3 =   {"Sriwijaya Air", "Soekarno Hatta (12:00)", "Ngurah Rai Bali(16:50)        ","SR909"};
    

    
    public :
    static bool isSeatAvailable(const vector<vector<string>>& kursipes, const string& seat);
    void firstclass();
    void economyclass();
    void bisnisclass();
    FlightDisplay();
    void queueNow();
    void merge(vector<JadwalPesawat>&, int, int, int);
    void mergeSort(vector<JadwalPesawat>&, int, int);
    void Pembayaran(){

    }
};

class Menu : public FlightDisplay {
    private :
    char pil;
    public :

    Menu();
    void menu();

};


int main() {
    utama();
}



void utama(){

    Menu m;
}

Menu::Menu(){
    menu();
}
void Menu::menu(){
    while (pil != '1' && pil != '2' && pil != '3' && pil != '4'){
        cout<<YELLOW<<"Pilih Kelas yang Anda inginkan"<<endl;
        cout<<"1. First Class"<<endl;
        cout<<"2. Bussiness class"<<endl;
        cout<<"3. Economy Class"<<endl;
        cout<<"4. Exit"<<endl;
        cin>>pil;
    }
        switch (pil){
            case '1' :
                firstclass();
                break;
            case '2' :
                bisnisclass();
                break;
            case '3' :
                economyclass();
                break;
            case '4' :
                clearScreen();
                footer();
                exit(0);
                break;
        }
    }

void HeaderFooter::Header(){
    cout<<RED << " _______                             __                                      ______                       __                                                     __    __             __      __               " << endl;
    cout<<RED << "|       \\                           |  \\                                    /      \\                     |  \\                                                   |  \\  |  \\           |  \\    |  \\              " << endl;
    cout<<RED << "| $$$$$$$\\  ______   _______    ____| $$  ______    ______   ______        |  $$$$$$\\  ______    ______  | $$   __  ______    ______   _______    ______        | $$  | $$  ______  _| $$_  _| $$_     ______  " << endl;
    cout<<RED << "| $$__/ $$ |      \\ |       \\  /      $$ |      \\  /      \\ |      \\       | $$___\\$$ /      \\  /      \\ | $$  /  \\|      \\  /      \\ |       \\  /      \\       | $$__| $$ |      \\|   $$ \\|   $$ \\   |      \\ " << endl;
    cout<<YELLOW << "| $$    $$  \\$$$$$$\\| $$$$$$$\\|  $$$$$$$  \\$$$$$$\\|  $$$$$$\\ \\$$$$$$\\       \\$$    \\ |  $$$$$$\\|  $$$$$$\\| $$_/  $$ \\$$$$$$\\|  $$$$$$\\| $$$$$$$\\|  $$$$$$\\      | $$    $$  \\$$$$$$\\$$$$$$ \\$$$$$$    \\$$$$$$\\" << endl;
    cout<<YELLOW << "| $$$$$$$\\ /      $$| $$  | $$| $$  | $$ /      $$| $$   \\$$/      $$       _\\$$$$$$\\| $$  | $$| $$    $$| $$   $$ /      $$| $$   \\$$| $$  | $$| $$  | $$      | $$$$$$$$ /      $$ | $$ __ | $$ __  /      $$" << endl;
    cout<<YELLOW << "| $$__/ $$|  $$$$$$$| $$  | $$| $$__| $$|  $$$$$$$| $$     |  $$$$$$$      |  \\__| $$| $$__/ $$| $$$$$$$$| $$$$$$\\|  $$$$$$$| $$      | $$  | $$| $$__/ $$      | $$  | $$|  $$$$$$$ | $$|  \\| $$|  \\|  $$$$$$$" << endl;
    cout<<GREEN << "| $$    $$ \\$$    $$| $$  | $$ \\$$    $$ \\$$    $$| $$      \\$$    $$       \\$$    $$ \\$$    $$ \\$$     \\| $$  \\$$\\\\$$    $$| $$      | $$  | $$ \\$$    $$      | $$  | $$ \\$$    $$  \\$$  $$ \\$$  $$ \\$$    $$" << endl;
    cout<<GREEN << " \\$$$$$$$   \\$$$$$$$ \\$$   \\$$  \\$$$$$$$  \\$$$$$$$ \\$$       \\$$$$$$$        \\$$$$$$   \\$$$$$$   \\$$$$$$$ \\$$   \\$$ \\$$$$$$$ \\$$       \\$$   \\$$  \\$$$$$$        \\$$   \\$$  \\$$$$$$$   \\$$$$   \\$$$$   \\$$$$$$$" << RESET<<endl;

        pesawat();
}

void HeaderFooter::footer(){
    cout<<RED << "  _____ _                 _     __   __           ______          ______ _       _                        _ _   _                 " << endl;
    cout<<RED << " |_   _| |               | |    \\ \\ / /           |  ___|         |  ___| |     (_)                      (_) | | |                " << endl;
    cout<<RED << "   | | | |__   __ _ _ __ | | __  \\ V /___  _   _  | |_ ___  _ __  | |_  | |_   _ _ _ __   __ _  __      ___| |_| |__    _   _ ___ " << endl;
    cout<<YELLOW << "   | | | '_ \\ / _` | '_ \\| |/ /   \\ // _ \\| | | | |  _/ _ \\| '__| |  _| | | | | | | '_ \\ / _` | \\ \\ /\\ / / | __| '_ \\  | | | / __|" << endl;
    cout<<YELLOW << "   | | | | | | (_| | | | |   <    | | (_) | |_| | | || (_) | |    | |   | | |_| | | | | | (_| |  \\ V  V /| | |_| | | | |_| \\__ \\" << endl;
    cout<<GREEN << "   \\_/ |_| |_|\\__,_|_| |_|_|\\_\\   \\_/\\___/ \\__,_| \\_| \\___/|_|    \\_|   |_|\\__, |_|_| |_|\\__, |   \\_/\\_/ |_|\\__|_| |_|  \\__,_|___/" << endl;
    cout<<GREEN << "                                                                            __/ |         __/ |                                   " << endl;
    cout<<GREEN << "                                                                           |___/         |___/                                    " << endl;
    pesawatFooter();
    kota();
    SoundBuffer s;
    if(!s.loadFromFile("end.wav")){
    }
    Sound sound;
    sound.setBuffer(s);
    sound.play();
    while (sound.getStatus() == sf::Sound::Playing) {
    }
}


void HeaderFooter::Welcome(){
        cout << RED << "\t\t\t\t\t\t\t .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .----------------. " << RESET << endl;
        cout << RED << "\t\t\t\t\t\t\t| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << RESET << endl;
        cout << RED << "\t\t\t\t\t\t\t| | _____  _____ | || |  _________   | || |   _____      | || |     ______   | || |     ____     | || | ____    ____ | || |  _________   | |" << RESET << endl;
        cout << RED << "\t\t\t\t\t\t\t| ||_   _||_   _|| || | |_   ___  |  | || |  |_   _|     | || |   .' ___  |  | || |   .'    `.   | || ||_   \\  /   _|| || | |_   ___  |  | |" << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t\t| |  | | /\\ | |  | || |   | |_  \\_|  | || |    | |       | || |  / .'   \\_|  | || |  /  .--.  \\  | || |  |   \\/   |  | || |   | |_  \\_|  | |" << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t\t| |  | |/  \\| |  | || |   |  _|  _   | || |    | |   _   | || |  | |         | || |  | |    | |  | || |  | |\\  /| |  | || |   |  _|  _   | |" << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t\t| |  |   /\\   |  | || |  _| |___/ |  | || |   _| |__/ |  | || |  \\ `.___.'\\  | || |  \\  `--'  /  | || | _| |_\\/_| |_ | || |  _| |___/ |  | |" << RESET << endl;
        cout << GREEN << "\t\t\t\t\t\t\t| |  |__/  \\__|  | || | |_________|  | || |  |________|  | || |   `._____.'  | || |   `.____.'   | || ||_____||_____|| || | |_________|  | |" << RESET << endl;
        cout << GREEN << "\t\t\t\t\t\t\t| |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << RESET << endl;
        cout << GREEN << "\t\t\t\t\t\t\t'----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << RESET << endl;
    }
void HeaderFooter::kota(){
    cout <<BLUE<< "                                       .                                       ." << endl;
    cout <<BLUE<< "              . .                     -:-             .  .  .              . .                     -:-             .  .  ." << endl;
    cout <<BLUE<< "            .'.:,'.        .  .  .     ' .           . \\ | / .            .'.:,'.        .  .  .     ' .           . \\ | / ." << endl;
    cout <<BLUE<< "            .'.;.`.       ._. ! ._.       \\          .__\\:/__.            .'.;.`.       ._. ! ._.       \\          .__\\:/__." << endl;
    cout <<BLUE<< "             `,:.'         . \\!/ .                     .';`.      . ' .             `,:.'         . \\!/ .                     .';`.      . ' .          `,:.'         . \\!/ .                     .';`.      . ' ." << endl;
    cout <<CYAN<< "             ,'             . ! .        ,.,      ..======..       .:.             ,'             . ! .        ,.,      ..======..       .:.         ,'             . ! .        ,.,      ..======..       .:." << endl;
    cout <<CYAN<< "            ,                 .         ._!_.     ||::: : | .        ',            ,                 .         ._!_.     ||::: : | .        ',         ,                 .         ._!_.     ||::: : | .        '," << endl;
    cout <<CYAN<< "     .====.,                  .           ;  .~.===: : : :|   ..===.     .====.,                  .           ;  .~.===: : : :|   ..===.====.,                  .           ;  .~.===: : : :|   ..===." << endl;
    cout <<CYAN<< "     |.::'||      .=====.,    ..=======.~,   |\"|: :|::::::|   ||:::|=====|     |.::'||      .=====.,    ..=======.~,   |\"|: :|::::::|   ||:::|=====|     |.::'||      .=====.,    ..=======.~,   |\"|: :|::::::|   ||:::|=====|" << endl;
    cout <<CYAN<< "  ___| :::|!__.,  |:::::|!_,   |: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :|  ___| :::|!__.,  |:::::|!_,   |: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :||  ___| :::|!__.,  |:::::|!_,   |: :: ::|\"|l_l|\"|:: |:;;:::|___!| ::|: : :|" << endl;
    cout <<CYAN<< " |: :|::: |:: |!__|; :: |: |===::: :: :|\"||_||\"| : |: :: :|: : |:: |:::::| |: :|::: |:: |!__|; :: |: |===::: :: :|\"||_||\"| : |: :: :|: : |:: |:::::|| |: :|::: |:: |!__|; :: |: |===::: :: :|\"||_||\"| : |: :: :|: : |:: |:::::|" << endl;
    cout <<CYAN<< " !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]! !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]! !_[]![_]_!_[]![]_!_[__]![]![_]![_][I_]!//_:_\\![]I![_][_]!_[_]![]_!_[__]!" << endl;
    cout <<GRAY<< " -----------------------------------\"---''''```---\"----------------------- -----------------------------------\"---''''```---\"------------------------- -----------------------------------\"---''''```---\"-----------------------" << endl;
    cout <<GRAY<< " _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ __ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ |= _ _:_ _ =| _ _ _ _ _ _ _ _ _ _ _ _" << endl;
    cout <<GRAY<< "                                     |=    :    =|                Valkyrie                                     |=    :    =|                Valkyrie                                     |=    :    =|                Valkyrie" << endl;
    cout <<GRAY<< "_____________________________________L___________J_____________________________________________________________L___________J_____________________________________________________________L___________J________________________" << endl;
    cout <<GRAY<< "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------" << RESET<< endl;
}

HeaderFooter::HeaderFooter(){
        clearScreen();
        Welcome();
        sleep(SLEEP_SCREEN);     
        clearScreen();
        to();
        sleep(SLEEP_SCREEN);     
        clearScreen();
        SoundBuffer buffer;
        if (!buffer.loadFromFile("atten.wav")){

        }
        Sound sound;
        sound.setBuffer(buffer);
        sound.play();
        Header();
        while (sound.getStatus() == sf::Sound::Playing) {

        }

        cout<<endl<<endl;

}
void HeaderFooter::to(){
        cout << RED << "\t\t\t\t\t\t\t.___________.  ______   " << RESET << endl;
        cout << RED << "\t\t\t\t\t\t\t|           | /  __  \\  " << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t\t`---|  |----`|  |  |  | " << RESET << endl;
        cout << YELLOW << "\t\t\t\t\t\t\t    |  |     |  |  |  | " << RESET << endl;
        cout << GREEN << "\t\t\t\t\t\t\t    |  |     |  `--'  | " << RESET << endl;
        cout << GREEN << "\t\t\t\t\t\t\t    |__|      \\______/  " << RESET << endl;
        cout << endl;
}
void HeaderFooter::pesawatFooter(){
    cout <<YELLOW<< "\t\t\t\t\t\t\t              .------," << endl;
    cout <<YELLOW<< "\t\t\t\t\t\t\t              =\\      \\" << endl;
    cout <<YELLOW<< "\t\t\t\t\t\t\t .---.         =\\      \\" << endl;
    cout <<YELLOW<<"\t\t\t\t\t\t\t | C~ \\         =\\      \\" << endl;
    cout <<BLUE<< "\t\t\t\t\t\t\t |     `----------'------'----------," << endl;
    cout <<BLUE<< "\t\t\t\t\t\t\t.'     LI.-.LI LI LI LI LI LI LI.-.LI`-." << endl;
    cout <<BLUE<< "\t\t\t\t\t\t\t\\ _/.____|_|______.------,______|_|_____)" << endl;
    cout <<BLUE<< "\t\t\t\t\t\t\t                 /      /" << endl;
    cout <<RED<< "\t\t\t\t\t\t\t               =/      /" << endl;
    cout <<RED<< "\t\t\t\t\t\t\t              =/      /" << endl;
    cout <<RED<< "\t\t\t\t\t\t\t             =/      /" << endl;
    cout <<RED<< "\t\t\t\t\t\t\t      jgs    /_____,'" << endl;
}

void HeaderFooter::pesawat(){
    cout<<endl;
    cout<<endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t                             |" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t                       --====|====--" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t                             |" << endl;
    cout << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t                         .-\"\"\"\"\"\"-. " << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t                       .'_________'. " << endl;
    cout<<BLUE << "\t\t\t\t\t\t\t                     ;'-._       _.-';" << endl;
    cout<<BLUE << "\t\t\t\t\t\t\t                      /_/_|__|__|_\\_\\" << endl;
    cout<<BLUE << "\t\t\t\t\t\t\t,--------------------|    `-. .-'    |--------------------," << endl;
    cout<<BLUE << "\t\t\t\t\t\t\t ``\"\"--..__    ___   ;       '       ;   ___    __..--\"\"``" << endl;
    cout<<RED << "\t\t\t\t\t\t\t  jgs      `\"-// \\\\.._\\             /_..// \\\\-\"`" << endl;
    cout<<RED << "\t\t\t\t\t\t\t              \\\\_//    '._       _.'    \\\\_//" << endl;
    cout<<RED << "\t\t\t\t\t\t\t               `\"`        ``---``        `\"`" << RESET <<endl;
    kota();
}


FlightDisplay::FlightDisplay(){
    queueNow();
}

bool FlightDisplay::isSeatAvailable(const vector<vector<string>>& kursipes, const string& seat){
    for (const vector<string>& row : kursipes) {
        for (const string& kursi : row) {
            if (kursi == seat) {
                return true;  
            }
        }
    }
    return false;  
}

void FlightDisplay::merge(vector<JadwalPesawat> &arr, int left, int middle, int right){
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Membuat vektor sementara untuk subvektor kiri dan kanan
    vector<JadwalPesawat> leftArr(n1);
    vector<JadwalPesawat> rightArr(n2);

    for (int i = 0; i < n1; i++) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; j++) {
        rightArr[j] = arr[middle + 1 + j];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        string hargaLeft = leftArr[i].harga.substr(4);
        string hargaRight = rightArr[j].harga.substr(4);
        hargaLeft.erase(remove(hargaLeft.begin(), hargaLeft.end(), '.'), hargaLeft.end());
        hargaLeft.erase(remove(hargaLeft.begin(), hargaLeft.end(), ','), hargaLeft.end());
        hargaRight.erase(remove(hargaRight.begin(), hargaRight.end(), '.'), hargaRight.end()); 
        hargaRight.erase(remove(hargaRight.begin(), hargaRight.end(), ','), hargaRight.end()); 
        long long hargaLeftNum = stoll(hargaLeft);
        long long hargaRightNum = stoll(hargaRight);
        if (hargaLeftNum < hargaRightNum) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Menyalin sisa elemen jika ada
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
}

void FlightDisplay::mergeSort(vector<JadwalPesawat> & arr, int left, int right){
    if (left < right) {
        int middle = left + (right - left) / 2;

        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        merge(arr, left, middle, right);
    }
}
void FlightDisplay::queueNow(){
    lepaspes.push(jad1);
    lepaspes.push(jad2);
    lepaspes.push(jad3);
    cout<<RED << "\t\t\t\t\t\t\t   ___                          _   _               \n";
    cout<<RED << "\t\t\t\t\t\t\t  / _ \\ _   _  ___ _   _  ___  | \\ | | _____      __\n";
    cout<<RED << "\t\t\t\t\t\t\t | | | | | | |/ _ \\ | | |/ _ \\ |  \\| |/ _ \\ \\ /\\ / /\n";
    cout<<YELLOW << "\t\t\t\t\t\t\t | |_| | |_| |  __/ |_| |  __/ | |\\  | (_) \\ V  V / \n";
    cout<<YELLOW << "\t\t\t\t\t\t\t  \\__\\_\\\\__,_|\\___|\\__,_|\\___| |_| \\_|\\___/ \\_/\\_/  \n";
    cout<<YELLOW << "\t\t\t\t\t\t\t                                                     \n";
    cout << RED << "\t\t\t\t\t\t\t+=====+=================================+==========+========================+==============================+\n";
    cout << RED << "\t\t\t\t\t\t\t| No. |             Plane               |  Boeing  |        Departure       |            Arrival           |\n";
    cout << RED << "\t\t\t\t\t\t\t+=====+=================================+==========+========================+==============================+\n";
    
    int scheduleNo = 1;
    while (!lepaspes.empty()) {
        JadwalPesawat schedule = lepaspes.front();
        lepaspes.pop();

        cout<<YELLOW << "\t\t\t\t\t\t\t| "<< scheduleNo<< setw(3) << left;
        cout << " "<< schedule;

        scheduleNo++;
    }

    cout << RED << "\t\t\t\t\t\t\t+=====+=================================+==========+========================+==============================+\n";
    cout << RESET;
    }




void FlightDisplay::bisnisclass(){
    char pil;
    string pil2, nama, notiket;
    char *p_pil = &pil;
    string *p_nama = &nama, *p_pil2 = &pil2 ,*p_notiket = &notiket ;
    mergeSort(jadwalBisnis, 0, jadwalBisnis.size()-1);

    while(pil != '1'&& pil != '2'&& pil != '3' && pil != '4'){
        clearScreen();
    cout<<RED << "\t\t\t\t\t\t\t\t  ____            _                        ____ _               " << endl;
    cout<<RED << "\t\t\t\t\t\t\t\t | __ ) _   _ ___(_)_ __   ___  ___ ___   / ___| | __ _ ___ ___ " << endl;
    cout<<RED << "\t\t\t\t\t\t\t\t |  _ \\| | | / __| | '_ \\ / _ \\/ __/ __| | |   | |/ _` / __/ __|" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t\t | |_) | |_| \\__ \\ | | | |  __/\\__ \\__ \\ | |___| | (_| \\__ \\__ \\" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t\t |____/ \\__,_|___/_|_| |_|\\___||___/___/  \\____|_|\\__,_|___/___/" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=============================+\n";
    cout<<YELLOW << "\t\t\t\t\t\t\t|  No. |              Plane               | Boeing  |         Price       |       Departure        |            Arrival          |\n";
    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=============================+\n";

    for (int i = 0; i < jadwalBisnis.size(); i++) {
        cout<< BLUE << "\t\t\t\t\t\t\t| " << setw(4) << i+1 << " | " << setw(32) << jadwalBisnis[i].namePlane << " | " << setw(7) << jadwalBisnis[i].boeing << " | "
                << setw(19) << jadwalBisnis[i].harga << " | " << setw(21) << jadwalBisnis[i].Departure << " | " << setw(23)
                << jadwalBisnis[i].arrival << " |\n";
    }

    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=============================+\n\n\n";
    cout<<"Silahkan Pilih Jadwal Yang Tersedia (Masukan sesuai urutan table ): "<<endl;
    cin>>pil;

    }
    
    int index = pil - '1';   

    if (pil == '1'||pil == '2' || pil == '3'|| pil == '4'|| pil == '5'){
        bool kursiTersedia = false;
        while(!kursiTersedia){
            clearScreen();
            cout<<YELLOW<<" Silahkan Pilih Kursi Yang Tersedia : "<<endl<<endl;
            for (int i = 0; i <kursibisnis.size(); i++){
                cout<<"\t\t\t\t\t\t\t";
                for (int j = 0; j < kursibisnis[i].size(); j++){
                    cout<<YELLOW<<"\t\t\t["<<kursibisnis[i][j]<<"] ";
                }
                cout<<endl<<endl<<endl;
            }
            cin.ignore();
            cin>>pil2;
            kursiTersedia = isSeatAvailable(kursibisnis, pil2);
    }
    
    cout<<"Masukan Nama Anda : "<<endl;
    cin.ignore();
    getline(cin,nama);
    cout<<"Masukan Nomor Tiket Anda : "<<RESET<<endl; 
    getline(cin,notiket);
    char pil3;
    while(pil3 != '1' && pil3 != '2' && pil3 != '3' && pil3 != '4'){
    clearScreen();
    cout << "Pilih Metode Pembayaran : "<<endl;
    cout << "1. m-Banking"<<endl;
    cout << "2. Dana" <<endl;
    cout << "3. LinkAja" << endl;
    cout << "4. Gopay" << endl;

    string nohp;
    cin>>pil3;

    switch(pil3){
        case '1' :
            cout<<"Silahkan Transfer Kode VA berikut : 123456789 dengan harga"<<jadwalBisnis[index].harga<<endl;
            pauseScreen();
            break;
        case '2' : case '3' : case '4' :
            cout<<" Masukan Nomor Telepon Anda : ";
            cin>>nohp;
            break;
    }


    }
    clearScreen();
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|            BUSSINESS CLASS            |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|       " << jadwalBisnis[index].namePlane << "|" << endl;
    cout << WHITE_BG << BLACK << "|++++++++++++++++++++++++++++++++++++ |" << endl;
    cout << WHITE_BG << BLACK << "| No Tiket : "<<notiket<<"                |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| Boeing :   " << jadwalBisnis[index].boeing << "|" << endl;
    cout << WHITE_BG << BLACK << "| Keberangkatan :" << jadwalBisnis[index].Departure << "|" << endl;
    cout << WHITE_BG << BLACK << "| Tiba :  " << jadwalBisnis[index].arrival << "|" << endl;
    cout << WHITE_BG << BLACK << "| Nama Penumpang :" << nama << "          |" << endl;
    cout << WHITE_BG << BLACK << "| Seat :" << pil2 << "          |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| total          IDR" << jadwalBisnis[index].harga << "|" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << RESET << endl;
    pauseScreen();
    clearScreen();
    footer();
}
}



void FlightDisplay::economyclass(){
    char pil;
    string pil2, nama, notiket;
    char *p_pil = &pil;
    string *p_nama = &nama, *p_pil2 = &pil2 ,*p_notiket = &notiket ;
    while(pil != '1'&& pil != '2'&& pil != '3' && pil != '4'&& pil != '5'){
    clearScreen();
    // sort(jadwaleconomy.begin(), jadwaleconomy.end(), compareByPrice );
    mergeSort(jadwaleconomy, 0, jadwaleconomy.size()-1);
    cout<<RED << "\t\t\t\t\t\t\t\t  _____                                         ____ _               " << endl;
    cout<<RED << "\t\t\t\t\t\t\t\t | ____|___ ___  _ __   ___  _ __ ___  _   _   / ___| | __ _ ___ ___ " << endl;
    cout<<RED << "\t\t\t\t\t\t\t\t |  _| / __/ _ \\| '_ \\ / _ \\| '_ ` _ \\| | | | | |   | |/ _` / __/ __|" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t\t | |__| (_| (_) | | | | (_) | | | | | | |_| | | |___| | (_| \\__ \\__ \\" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t\t |_____\\___\\___/|_| |_|\\___/|_| |_| |_|\\__, |  \\____|_|\\__,_|___/___/" << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t\t                                       |___/                          " << endl;
    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+======================+========================+=========================+\n";
    cout<<YELLOW << "\t\t\t\t\t\t\t|  No. |             Plane                | Boeing  |         Price        |       Departure        |          Arrival        |\n";
    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+======================+========================+=========================+\n";

    for (int i = 0; i < jadwaleconomy.size(); i++) {
        cout<< BLUE << "\t\t\t\t\t\t\t| " << setw(4) << i+1 << " | " << setw(32) << jadwaleconomy[i].namePlane << " | " << setw(7) << jadwaleconomy[i].boeing << " | "
                << setw(19) << jadwaleconomy[i].harga << " | " << setw(21) << jadwaleconomy[i].Departure << " | " << setw(23)
                << jadwaleconomy[i].arrival << " |\n";
    }

    cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+======================+========================+=========================+\n\n\n";
    cout<<"Silahkan Pilih Jadwal Yang Tersedia (Masukan sesuai urutan table ): "<<endl;
    cin>>pil;
    }
    int index = pil - '1';   

    if (pil == '1'||pil == '2' || pil == '3'|| pil == '4'|| pil == '5'){
        bool kursiTersedia = false;
        while(!kursiTersedia){
            clearScreen();
            cout<<YELLOW<<" Silahkan Pilih Kursi Yang Tersedia : "<<endl<<endl;
            for (int i = 0; i <kursiekonomi.size(); i++){
                cout<<"\t\t\t\t\t\t\t";
                for (int j = 0; j < kursiekonomi[i].size(); j++){
                    cout<<YELLOW<<"\t\t\t["<<kursiekonomi[i][j]<<"] ";
                }
                cout<<endl<<endl<<endl;
            }
            cin.ignore();
            cin>>pil2;
            kursiTersedia = isSeatAvailable(kursiekonomi, pil2);
    }
    
    cout<<"Masukan Nama Anda : "<<endl;
    cin.ignore();
    getline(cin,nama);
    cout<<"Masukan Nomor Tiket Anda : "<<RESET<<endl; 
    getline(cin,notiket);
    char pil3;
    while(pil3 != '1' && pil3 != '2' && pil3 != '3' && pil3 != '4'){
    clearScreen();
    cout << "Pilih Metode Pembayaran : "<<endl;
    cout << "1. m-Banking"<<endl;
    cout << "2. Dana" <<endl;
    cout << "3. LinkAja" << endl;
    cout << "4. Gopay" << endl;

    string nohp;
    cin>>pil3;

    switch(pil3){
        case '1' :
            cout<<"Silahkan Transfer Kode VA berikut : 123456789 dengan harga"<<jadwaleconomy[index].harga<<endl;
            pauseScreen();
            break;
        case '2' : case '3' : case '4' :
            cout<<" Masukan Nomor Telepon Anda : ";
            cin>>nohp;
            break;
    }


    }
    clearScreen();
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|            ECONOMY CLASS            |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|       " << jadwaleconomy[index].namePlane << "|" << endl;
    cout << WHITE_BG << BLACK << "|++++++++++++++++++++++++++++++++++++ |" << endl;
    cout << WHITE_BG << BLACK << "| No Tiket : "<<notiket<<"                |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| Boeing :   " << jadwaleconomy[index].boeing << "|" << endl;
    cout << WHITE_BG << BLACK << "| Keberangkatan :" << jadwaleconomy[index].Departure << "|" << endl;
    cout << WHITE_BG << BLACK << "| Tiba :  " << jadwaleconomy[index].arrival << "|" << endl;
    cout << WHITE_BG << BLACK << "| Nama Penumpang :" << nama << "          |" << endl;
    cout << WHITE_BG << BLACK << "| Seat :" << pil2 << "          |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| total          IDR" << jadwaleconomy[index].harga << "|" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << RESET << endl;
    pauseScreen();
    clearScreen();
    footer();
}
}
void FlightDisplay::firstclass(){
    char pil;
    string pil2, nama, notiket;
    char *p_pil = &pil;
    string *p_nama = &nama, *p_pil2 = &pil2 ,*p_notiket = &notiket ;
    mergeSort(jadwalFirst, 0, jadwalFirst.size()-1);
    while(*p_pil != '1'&& *p_pil != '2'&& *p_pil != '3'){
        clearScreen();
        cout<<RED << "\t\t\t\t\t\t\t\t\t  _____ _          _      ____ _               " << endl;
        cout<<RED << "\t\t\t\t\t\t\t\t\t |  ___(_)_ __ ___| |_   / ___| | __ _ ___ ___ " << endl;
        cout<<RED << "\t\t\t\t\t\t\t\t\t | |_  | | '__/ __| __| | |   | |/ _` / __/ __|" << endl;
        cout<<YELLOW << "\t\t\t\t\t\t\t\t\t |  _| | | |  \\__ \\ |_  | |___| | (_| \\__ \\__ \\" << endl;
        cout<<YELLOW << "\t\t\t\t\t\t\t\t\t |_|   |_|_|  |___/\\__|  \\____|_|\\__,_|___/___/" << endl;
        cout<<YELLOW << "\t\t\t\t\t\t\t\t\t                                               " << endl;
        cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=================================+\n";
        cout<<YELLOW << "\t\t\t\t\t\t\t|  No. |             Plane                | Boeing  |        Price        |       Departure        |             Arrival             |\n";
        cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=================================+\n";

        for (int i = 0; i < jadwalFirst.size(); i++) {
            cout<< BLUE << "\t\t\t\t\t\t\t| " << setw(4) << i+1 << " | " << setw(32) << jadwalFirst[i].namePlane << " | " << setw(7) << jadwalFirst[i].boeing << " | "
                    << setw(19) << jadwalFirst[i].harga << " | " << setw(21) << jadwalFirst[i].Departure << " | " << setw(23)
                    << jadwalFirst[i].arrival << " |\n";
        }

        cout<<YELLOW << "\t\t\t\t\t\t\t+======+==================================+=========+=====================+========================+=================================+\n\n\n";
        cout<<"Silahkan Pilih Jadwal Yang Tersedia (Masukan sesuai urutan table ): "<<endl;
        cin>>*p_pil;
}
    int index = *p_pil - '1';   
    if (pil == '1'||pil == '2' || pil == '3'){
        bool kursiTersedia = false;

        while(!kursiTersedia){
            clearScreen();
            cout<<YELLOW<<" Silahkan Pilih Kursi Yang Tersedia : "<<endl<<endl;
            for (int i = 0; i <kursifirst.size(); i++){
                cout<<"\t\t\t\t\t\t\t";
                for (int j = 0; j < kursifirst[i].size(); j++){
                    cout<<YELLOW<<"\t\t\t["<<kursifirst[i][j]<<"] ";
                }
                cout<<endl<<endl<<endl;
            }
            cin.ignore();
            cin>>*p_pil2;
            kursiTersedia = isSeatAvailable(kursifirst, *p_pil2);
    }
    
    cout<<"Masukan Nama Anda : "<<endl;
    cin.ignore();
    getline(cin,*p_nama);
    cout<<"Masukan Nomor Tiket Anda : "<<endl; 
    getline(cin,*p_notiket);
    char pil3;
    while(pil3 != '1' && pil3 != '2' && pil3 != '3' && pil3 != '4'){
    clearScreen();
    cout << "Pilih Metode Pembayaran : "<<endl;
    cout << "1. m-Banking"<<endl;
    cout << "2. Dana" <<endl;
    cout << "3. LinkAja" << endl;
    cout << "4. Gopay" << endl;

    string nohp;
    cin>>pil3;

    switch(pil3){
        case '1' :
            cout<<"Silahkan Transfer Kode VA berikut : 123456789 dengan harga"<<jadwalFirst[index].harga<<endl;
            pauseScreen();
            break;
        case '2' : case '3' : case '4' :
            cout<<" Masukan Nomor Telepon Anda : ";
            cin>>nohp;
            break;
    }


    }

    clearScreen();
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|            FIRST CLASS              |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "|       " << jadwalFirst[index].namePlane << "|" << endl;
    cout << WHITE_BG << BLACK << "|++++++++++++++++++++++++++++++++++++ |" << endl;
    cout << WHITE_BG << BLACK << "| No Tiket : "<<notiket<<"                |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| Boeing :   " << jadwalFirst[index].boeing << "|" << endl;
    cout << WHITE_BG << BLACK << "| Keberangkatan :" << jadwalFirst[index].Departure << "|" << endl;
    cout << WHITE_BG << BLACK << "| Tiba :  " << jadwalFirst[index].arrival << "|" << endl;
    cout << WHITE_BG << BLACK << "| Nama Penumpang :" << nama << "          |" << endl;
    cout << WHITE_BG << BLACK << "| Seat :" << pil2 << "          |" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "| total          IDR" << jadwalFirst[index].harga << "|" << endl;
    cout << WHITE_BG << BLACK << "|                                     |" << endl;
    cout << WHITE_BG << BLACK << "+-------------------------------------+" << RESET << endl;
    pauseScreen();
    clearScreen();
    footer();
    }
    

}
void clearScreen(){
    #ifdef _WIN32 
        system("cls");
    #else
        system("clear");
    #endif
}

void pauseScreen(){
    #ifdef _WIN32 
        system("pause>0");
    #else
        system("sleep 3");
    #endif
}