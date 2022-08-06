#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <map>
#include <algorithm>
#include <any>
using namespace std;

struct variables {
	string type;
	string name;
	any value;
};

map<string, string> keyWords = {
	{ "tiv", "variable"   },
	{ "ket", "variable"   },
        { "bar", "variable"   },
	{ "gum", "arithmetic" },
	{ "han", "arithmetic" },
	{ "baz", "arithmetic" },
	{ "baj", "arithmetic" },
        { "ete", "condition"  },
        { "frfrik","loop"     },
	{ "tpel", "print"     },
	{  "]", "operator"    },
};

vector<string> operators = { "mec", "poqr", "havasar", "mechav", "poqhav"};
vector<string> words;
vector<variables> var;
vector<string> for_lines; 

bool condition_brackets = false;
bool for_isConditionTrue = false;
bool if_isConditionTrue = false;
bool it_for = false;

void  tokens(string line){
   string word;
   stringstream obj(line);

	 while (getline(obj, word, ' ')) {
       words.push_back(word);
	}
}

string checkKeyWords(){
	auto value = keyWords.find(words[0]);
    if (value == keyWords.end()) {
         cout << "Syntax Error: keyword "<< words[0] << " doesnt exist"   << endl;
         exit(0);
    }
    return value->second;
}

void individualName(){
    for (int i = 0; i < var.size(); ++i) {
      if(var[i].name == words[1]){
       cout << "Error: You already have variable with name " << words[1] << endl;
       exit(0);
      }
    }
}


void defineVariable(){
  if(words.size() < 3 || words.size() > 4 ){
     cout << "Syntax Error: too many or too weak arguments" << endl;
     exit(0);
  }
  if(words[0] == "tiv"){
  try { 
  	 var.push_back({ words[0], words[1], stoi(words[3])});
  }
  catch(exception &err) {
     cout << "Semantic Error: cant assign " << words[3] << " to tiv" << endl;
 	 exit(0);
     }
   }else if(words[0] == "ket"){
  try {
	 var.push_back({ words[0], words[1], stof(words[3])});
  }
  catch(exception &err) {
     cout << "Semantic Error: cant assign " << words[3] << " to ket" << endl;
     exit(0); 
  }
 } else var.push_back({ words[0], words[1], words[3]});

}

void print(){
    for(int i = 1; i < words.size(); ++i){
        if(words[i] != "<<" ){
            cout << words[i] <<  " ";
            if(i == words.size() - 1){
                cout << endl;
            }
        }  else {
           int j;
            for (j = 0; j < var.size(); ++j) {
              if(var[j].name == words[i + 1]){
              if(var[j].type == "tiv"){
                cout << any_cast<int>(var[j].value);
              }else if(var[j].type == "ket"){
                cout << any_cast<float>(var[j].value);
              }else  cout << any_cast<string>(var[j].value);
                 break;
              }
         }
         cout << endl;
         if(j == var.size()){
         cout << "Error: You dont have variable with name " << words[i + 1] << endl;
         exit(0);
         }
         break;
          }
       }
   }

void gum(){
        for (int i = 0; i < var.size(); ++i) {
            if(var[i].name == words[1]){
             if(var[i].type == "tiv" ){
               var[i]. value =  any_cast<int>(var[i].value) + stoi(words[2]);
               } else if(var[i].type == "ket"){
               var[i]. value =  any_cast<float>(var[i].value) + stof(words[2]);
               } else {
                 cout << "Error: type of " << words[1] << " is not tiv or ket" << endl;
                 exit(0);
               }
                break;
                 }
              if( i == var.size() - 1){
                cout << "Error: you dont have variable with name " << words[1] << endl;
                exit(0);
                }
          }
 }

 void han(){
         for (int i = 0; i < var.size(); ++i) {
             if(var[i].name == words[1]){
              if(var[i].type == "tiv"){
                var[i]. value =  any_cast<int>(var[i].value) - stoi(words[2]);
                } else if(var[i].type == "ket"){
                var[i]. value =  any_cast<float>(var[i].value) - stof(words[2]);
                } else {
                  cout << "Error: type of " << words[1] << " is not tiv or ket" << endl;
                  exit(0);
                }
                 break;
                  }
               if( i == var.size() - 1){
                 cout << "Error: you dont have variable with name " << words[1] << endl;
                 exit(0);
                 }

           }
  }

  void baz(){
          for (int i = 0; i < var.size(); ++i) {
              if(var[i].name == words[1]){
               if(var[i].type == "tiv"){
                 var[i]. value =  any_cast<int>(var[i].value) * stoi(words[2]);
                 } else if(var[i].type == "ket"){
                 var[i]. value =  any_cast<float>(var[i].value) * stof(words[2]);
                 } else {
                   cout << "Error: type of " << words[1] << " is not tiv or ket" << endl;
                   exit(0);
                 }
                  break;
                   }
                if( i == var.size() - 1){
                  cout << "Error: you dont have variable with name " << words[1] << endl;
                  exit(0);
                  }

            }
   }

   void baj(){
           for (int i = 0; i < var.size(); ++i) {
               if(stoi(words[2]) == 0){
                cout << "Error: can't divide by zero "<< endl;
                exit(0);
               }
               if(var[i].name == words[1]){
                if(var[i].type == "tiv"){
                  var[i]. value =  any_cast<int>(var[i].value) / stoi(words[2]);
                  } else if(var[i].type == "ket"){
                  var[i]. value =  any_cast<float>(var[i].value) / stof(words[2]);
                  } else {
                    cout << "Error: type of " << words[1] << " is not tiv or ket" << endl;
                    exit(0);
                  }
                   break;
                    }
                 if( i == var.size() - 1){
                   cout << "Error: you dont have variable with name " << words[1] << endl;
                   exit(0);
                   }

             }
    }

void arithmetic(){
 try {
    if (words.size() < 3) {
      cout << "Error few arguments" << endl;
      exit(0);
     }
    if (words[0] == "gum") {
       gum();
    } else if(words[0] == "han") {
       han();
    } else if(words[0] == "baz") {
       baz();
    } else baj();

   } catch(exception &err) {
          cout << "Error: during arithmetic calculation " << endl;
          exit(0);
       }
}

bool isCondition(){
    for (int i = 0; i < var.size(); ++i) {
       if(var[i].name == words[2]){
          if(var[i].type == "tiv") {
                 if(words[1] == "mec") {
                    return any_cast<int>(var[i].value) > stoi(words[3]);
                 } else if(words[1] == "poqr") {
                    return any_cast<int>(var[i].value) < stoi(words[3]);
                 } else if(words[1] == "havasar") {
                    return any_cast<int>(var[i].value) == stoi(words[3]);
                 } else if(words[1] == "mechav") {
                    return any_cast<int>(var[i].value) >= stoi(words[3]);
                 } else if(words[1] == "poqhav") {
                    return any_cast<int>(var[i].value) <= stoi(words[3]);
                 }
           } else if(var[i].type == "ket"){
                 if(words[1] == "mec") {
                    return any_cast<float>(var[i].value) > stof(words[3]);
                 } else if(words[1] == "poqr") {
                    return any_cast<float>(var[i].value) < stof(words[3]);
                 } else if(words[1] == "havasar") {
                    return any_cast<float>(var[i].value) == stof(words[3]);
                 } else if(words[1] == "mechav") {
                    return any_cast<float>(var[i].value) >= stof(words[3]);
                 } else if(words[1] == "poqhav") {
                    return any_cast<float>(var[i].value) <= stof(words[3]);
                 }
           } else {
              cout << "Error: type of " << words[1] << " is not tiv or ket" << endl;
              exit(0);
           }
           break;
           }
          if( i == var.size() - 1){
             cout << "Error: you dont have variable with name " << words[2] << endl;
             exit(0);
          }
             }
        return false;
}

bool Condition() {
try{
     if(words.size() < 5) {
        cout << "Error: few arguments" << endl;
        exit(0);
     }
     if(find(operators.begin(), operators.end(), words[1]) == operators.end()){
        cout<< "Error: invalid operator "<< words[1] << endl;
        exit(0);
     }
      if(words[4] != "["){
        cout<< "Error: condition brackets doesnt exist" << endl;
        exit(0);
      } else condition_brackets = true;
      if(words[0] == "frfrik") {
        it_for = true;
      }
         return isCondition();

     } catch(exception &err) {
              cout << "Error: during arithmetic calculation " << endl;
              exit(0);
           }
   }

void read_file(string path) {
  ifstream fin;
  fin.open(path);

  if (!fin.is_open())
  {
     cout << "Opening file error!" << endl;   
  } else {

  string str,sent;
  while (!fin.eof())
  {
    str = "";
	getline(fin, str);
    tokens(str);

    if(words[0] == "??"){
        str = "";
        words.clear();
        continue;
    }
    if(words[0] == "]"){
      condition_brackets = false;
    }
    if(condition_brackets && !it_for){
        if(!if_isConditionTrue && it_for){
           str = "";
           words.clear();
           continue;
        }
    }
    if(condition_brackets && it_for){
        if(!for_isConditionTrue){
           str = "";
           words.clear();
           for_lines.clear();
           continue;
        } else {
        for_lines.push_back(str);
        }
    }

    if(!condition_brackets && for_lines.size() != 0) {
      while(for_isConditionTrue){
        for (const string& str : for_lines) {
         tokens(str);
         if(words[0] == "??"){
                words.clear();
                continue;
         }
          string key = checkKeyWords();
           if(key == "variable") {
                individualName();
         	    defineVariable();
         	} else if(key == "print") {
         	    print();
         	} else if(key == "arithmetic") {
         	    arithmetic();
         	} else if(key == "condition") {
         	    cout<< str << endl;
         	    if_isConditionTrue = Condition();
         	} else if(key == "loop") {
               	for_isConditionTrue = Condition();
               	if(!for_isConditionTrue){
               	 condition_brackets = false;
               	  break;
               	}
            }
         	words.clear();
        }
      }
      str = "";
      words.clear();
      for_lines.clear();
      continue;
    }

    string key = checkKeyWords();

    if(key == "variable") {
        individualName();
	    defineVariable();
	} else if(key == "print") {
	    print();
	} else if(key == "arithmetic") {
	    arithmetic();
	} else if(key == "condition") {
	    if_isConditionTrue = Condition();
	} else if(key == "loop") {
      	for_isConditionTrue = Condition();
      	for_lines.push_back(str);
    }

	str = "";
	words.clear();
 }
  if(condition_brackets) {
     cout<< "Error: closing condition brackets doesnt exist" << endl;
     exit(0);
  }
  fin.close();
 
  }
 }
