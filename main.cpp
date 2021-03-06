#include <iostream>
#include <map>
#include <vector>
#include <ctime>
#include <unistd.h>
#include <sstream>
#include <windows.h>

using namespace std;

struct timestampflag{
    time_t time;
    bool status;
};

//multimap<string, timestampflag> tagidmmap; //pair<time_t,bool>
multimap<string, pair<time_t,bool>> tagidmmap;

template<typename T>
string toString(const T &t)
{
    ostringstream oss;
    oss << t;
    return oss.str();
}

template<typename T>
T fromString( const string& s )
{
    istringstream stream( s );
    T t;
    stream >> t;
    return t;
}

string MapKeysToString(map<time_t,bool> timeflag)
{
    string keystring = "";
    map<time_t,bool>::iterator timeit;
    for(timeit = timeflag.begin(); timeit != timeflag.end(); ++timeit)
    {
        cout << "Time Stamp: " << timeit->first << " - Flag: " <<  timeit->second << endl;
        keystring = toString(timeit->first)+","+keystring;
    }
    return keystring;
}

int main()
{
    cout << "Vetor Map Test Application!" << endl;

    map<string, map<time_t, bool> > tagIDMAP;

    map<string, vector<int> > containerNumberTimeMAP;
    string cotainernumber = "ADLJ12380982734";
    vector<int> cntTimer;
    cntTimer.push_back(12);
    cntTimer.push_back(16);
    containerNumberTimeMAP[cotainernumber] = cntTimer;
    cout<<"Vector Size: "<<cntTimer.size() << " Map size: " <<containerNumberTimeMAP.size() <<endl;
    int i;
    for(i =0; i < 5; i++)
    {
        time_t now = time(0);
        tagIDMAP[cotainernumber][now] = false;
        timestampflag tsv;
        tsv.time = now;
        tsv.status = false;
        pair<time_t,bool> timeflag(now,false);
        tagidmmap.insert (cotainernumber) = timeflag;
        //tagidtimestampflag(cotainernumber).status = false;
        cout <<"Time: " << now << endl;

#ifdef linux
        sleep(1);
        usleep(1000 * 1000 );
#else
        Sleep(1000);
#endif

    }
    cout<<"MAP of Map Size: "<<tagIDMAP[cotainernumber].size() << " Map size: " <<tagIDMAP.size() <<endl;

    string val = MapKeysToString(tagIDMAP[cotainernumber]);

    cout << "String Separated Data: " << val <<endl;

    return 0;
}
