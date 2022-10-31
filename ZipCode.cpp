#include <iostream> 
#include <string> 
#include <algorithm> 
#include <vector> 
#include <map> 

using namespace std; 
class Letter{
public:
    string name; 
    string address; 
    string province; 
    string district; 
    int zip; 
    bool operator < (const Letter& other) const {
    //**Begin Insert**
    if((this -> zip) < other.zip){
        return true;
    }
    else if((this -> zip) > other.zip){
        return false;
    }
    else if ((this -> zip) == other.zip){
        if((address).compare(other.address) < 0){
            return true;
        }
        else if((address).compare(other.address) > 0){
            return false;
        }
        else if ((address).compare(other.address) == 0){
            if(district.compare(other.district) < 0){
                return true;
            }
            else if(district.compare(other.district) > 0){
                return false;
            }
            else if(district.compare(other.district) == 0){
                if(province.compare(other.province) < 0){
                    return true;
                }
                else if(province.compare(other.province) > 0){
                    return false;
                }
                else if(province.compare(other.province) == 0){
                    if(name.compare(other.name) < 0){
                        return true;
                    }
                    else if(name.compare(other.name) > 0){
                        return false;
                    }
                    else if(name.compare(other.name) == 0){
                        return false;
                    }
                }
            }
        }
    }
    return false; 
    }
};
class ZipInfo{ 
public:
    int zip;
    string province; 
    string district;
};
void correctZipAndSortLetters(vector<ZipInfo>& zipinfo, vector<Letter>& letters) { 
    //**Begin Insert**
    map<pair<string,string>,int> check;
    for(ZipInfo &x : zipinfo){
        pair<string,string> a;
        a.first = x.province;
        a.second = x.district;
        check[a] = x.zip;
    }
    for(Letter &x : letters){
        pair<string,string> b;
        b.first = x.province;
        b.second = x.district;
        if(check[b] != x.zip){
            x.zip = check[b];
        }
    }
    sort(letters.begin(),letters.end());
    //**End Insert** 
}
int main() { 
    int nzip;
    cin>>nzip; 
    vector<ZipInfo> zipinfo; 
    for (int i = 0; i < nzip; i++) {
        ZipInfo z; cin>>z.zip>>z.district>>z.province; zipinfo.push_back(z);
    }
    int n;
    cin>>n;
    vector<Letter> letters; 
    for (int i = 0; i < n; i++) {
        Letter l; cin>>l.name>>l.address>>l.district>>l.province>>l.zip; letters.push_back(l);
    }
    correctZipAndSortLetters(zipinfo, letters); 
    for (auto& l:letters) {
        cout<<l.name<<" "<<l.address<<" "<<l.district<<" "<<l.province<<" "<<l.zip<<endl;
    }
}
