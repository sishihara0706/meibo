#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;


class Hito
{
    string name;
    string phone;
  public:
    void SetName(string n){
      name = n;
    }
    string GetName() const{
      return name;
    }
    void SetPhone(string p){
      phone = p;
    }
    string GetPhone() const{
      return phone;
    }
};

class Meibo{
    vector<Hito> data;
  public:
    // データを追加
    void AppendData();
    // 全データの出力
    void ShowAll() const;
    // meibo.txtからデータを読み出す関数
    void ReadData();
    // meibo.txtにデータを保存する関数
    void SaveData() const;
};

void Meibo::AppendData(){
  string s;
  Hito h;
  cout << "氏名を入力:";
  cin >> s;
  h.SetName(s);
  cout << "電話番号を入力:";
  cin >> s;
  h.SetPhone(s);
  data.push_back(h);
}

void Meibo::ShowAll() const{
  for(vector<Hito>::size_type i = 0; i < data.size(); i++){
    cout << "第" << i + 1 << "番" << endl;
    cout << data[i].GetName() << endl;
    cout << data[i].GetPhone() << endl;
    cout << "-------" << endl;
  }
}

void Meibo::ReadData(){
  ifstream f("meibo.txt");
  string s;
  Hito h;
  while(1){
    f >> s;
    if(s == "xxx") break;
    h.SetName(s);
    f >> s;
    h.SetPhone(s);
    data.push_back(h);
  }
}

void Meibo::SaveData() const{
  ofstream f("meibo.txt");
  for(vector<Hito>::size_type i = 0; i < data.size(); i++){
    f << data[i].GetName() << endl;
    f << data[i].GetPhone() << endl;
  }
  f << "xxx";
}

int main()
{
  Meibo abook;
  int a;
  abook.ReadData();
  while(1){
    cout << "名簿のプログラムです。 次に何をしますか?" << endl;
    cout << "1 データ追加  2 データ一覧  3 終了 (半角数字で入力):" << endl;
    cin >> a;
    if(a == 1){
      abook.AppendData();
    }
    else if(a == 2){
      abook.ShowAll();
    }
    else if(a == 3){
      break;
    }
    else{
      cout << "正しく入力してください。" << endl;
    }
  }
  abook.SaveData();

  return 0;
}