
using namespace std;
void func_and (char* func_in, int func_in_size){
    bool* outputval = new bool[func_in_size];
    //print header 
    for (int i = 0; i < func_in_size; i++){
        cout<<func_in[i]<<" ";
    }
    cout<<"| ";
    for (int i = 0; i < func_in_size; i++){
        cout<<func_in[i]<<"*";
    }
    cout<<endl<<"----------------------------------------"<<endl;
    //call logic_add()
}

void func_or (char* func_in, int func_in_size){
    bool* outputval = new bool[func_in_size];
    //print header
    for (int i = 0; i < func_in_size; i++){
        cout<<func_in[i]<<" ";
    }
    cout<<"| ";
    for (int i = 0; i < func_in_size; i++){
        cout<<func_in[i]<<"+";
    }
    cout<<endl<<"----------------------------------------"<<endl;
    //call logic_add()
}

void logic_and(bool* out, char* func_in, int count) {
    if (func_in[count] == 0){
        string result = "T";
        for (int i = 0; i < count; i++){
            if (cout[count]) {
                cout << "T ";
            } else {
                cout << "F ";
                result = "F";
            }
        }
        cout << "| " << result << endl;
    }
    //case 0
    out[count] = true;
    logic_and(out,func_in,++count);
    //case 1 
    out[count] = false;
    logic_and(out,func_in,++count);

}

void logic_or(bool* out) {

}