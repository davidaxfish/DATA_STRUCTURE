#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

#define MAX_VERTICE 50 /*maximum number of vertices*/
typedef struct node *node_pointer;
typedef struct node{
    int row;
    int col;
    struct node *link;
};
//vector <node_pointer>* VERTEX_LIST=new vector<node_pointer>(MAX_VERTICE);
vector <node_pointer> VERTEX_LIST;
vector <vector<int>> ADJACENT_LIST;
int n=0;
/*vertices currently in use*/


void buid_matrix(vector<vector<char> >*M){
    //cout<<"here size get"<<(*M).size()<<(*M)[0].size()<<endl;
    int row=(*M)[0].size();
    int col=(*M).size()/(*M)[0].size();
    char ele;
    for(int k=0;k<col;k++){
        (*M)[0][k]='.';
    }

    for(int j=1;j<row-1;j++){
        (*M)[j][0]='.';
        for(int i=1;i<col-1;i++){
            cin>>ele;
            (*M)[j][i]=ele;
        }
        (*M)[j][col-1]='.';

    }
    for(int h=0;h<col;h++){
        (*M)[row-1][h]='.';
    }
}

void GRAPH_LIST_generation(vector<vector<char> >*M){
    int row=(*M)[0].size();
    int col=(*M).size()/(*M)[0].size();
    for(int j=1;j<row-1;j++){
        for(int i=1;i<col-1;i++){
        //下面生成graph
        if(((*M)[j][i])=='*'){
            //cout<<"row="<<i<<" col="<<j<<" ="<<(*M)[j][i]<<endl;
            node_pointer vertex;
            vertex=(node_pointer)malloc(sizeof(node_pointer));
            vertex->row=j;vertex->col=i;
            VERTEX_LIST.push_back(vertex);
            //test
            //cout<<(*VERTEX_LIST)[0]<<endl;
        }
        else{}
        //上面生成graph
        }
        cout<<endl;
    }


    /*
    while(VERTEX_LIST.empty()!=true){
        cout<<(VERTEX_LIST.back())->row<<" "<<(VERTEX_LIST.back())->col<<endl;
        cout<<VERTEX_LIST[0]->row<<VERTEX_LIST[0]->col<<endl;
        VERTEX_LIST.pop_back();
    }*/
    //cout<<"judge start"<<endl;


    for(int loc=0;loc<VERTEX_LIST.size();loc++){
        vector<int> adjacent_unit;
        for(int k=0;k<VERTEX_LIST.size();k++){
            //cout<<VERTEX_LIST[k]->col<<endl;
            //檢查比鄰
            if((loc!=k)&&((abs(VERTEX_LIST[k]->col-VERTEX_LIST[loc]->col)<2)&&(abs(VERTEX_LIST[k]->row-VERTEX_LIST[loc]->row)<2))){
                //cout<<"in the judgement"<<endl;
                adjacent_unit.push_back(k);
            }
        }
        ADJACENT_LIST.push_back(adjacent_unit);
        adjacent_unit.clear();

    }
    for(int t=0;t<ADJACENT_LIST.size();t++){
        cout<<"the connected unit ["<<t<<"] number ="<<ADJACENT_LIST[t].size()<<endl;
        /*
        for(int h=0;h<ADJACENT_LIST[t].size();h++){
            cout<<"{"<<ADJACENT_LIST[t][h]<<"}";
        }*/
    cout<<endl;
    }

}



int main(){
    int i,j;
    while((i!=0)&&(j!=0)){
        cin>>i>>j;
        vector<vector<char> >*M = new vector<vector<char> >((i+2)*(j+2), vector<char>(i+2));
        //cout<<(*M).size()<<endl;
        buid_matrix(M);
        GRAPH_LIST_generation(M);
    }

    return 0;
}

