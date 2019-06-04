
using namespace std;

void logic_and(bool* out, char* func_in, int count) {

    if (func_in[count] == 0){
        string result = "T";
        for (int i = 0; i < count; i++){
            if (out[i]) {
                cout << "T ";
            } else {
                cout << "F ";
                result = "F";
            }
        }
        cout << "| " << result << endl;
        return;
    }
    //case 0
    out[count] = false;
    logic_and(out,func_in,count + 1);
    //case 1 
    out[count] = true;
    logic_and(out,func_in,count + 1);

}

void logic_or(bool* out, char* func_in, int count) {
    if (func_in[count] == 0){
        string result = "F";
        for (int i = 0; i < count; i++){
            if (out[i]) {
                cout << "T ";
                result = "T";
            } else {
                cout << "F ";
            }
        }
        cout << "| " << result << endl;
        return;
    }
    //case 0
    out[count] = false;
    logic_or(out,func_in,count + 1);
    //case 1 
    out[count] = true;
    logic_or(out,func_in,count + 1);
}

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
    logic_and(outputval,func_in,0);
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
    logic_or(outputval,func_in,0);
}