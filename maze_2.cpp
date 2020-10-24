#include <iostream>
#include <vector> // for 2D vector
using namespace std;
//maze class
typedef class mazevec{
    public:
        vector<vector<int> > stuff;
        //input the maze
        vector<vector<int> > build_maze(int col, int row){
            int block;
            //�o����G�S���u���N�q�W��n�x�}
            vector<int> edge;

            for(int k=0;k<col+2;k++){
                edge.push_back(1);
            }
            stuff.push_back(edge);
            for(int i=0;i<row;i++){
                    vector<int> temp={};
                    temp.push_back(1);
                    for(int j=0;j<col;j++){
                        cin>>block;
                        temp.push_back(block);
                    }
                    temp.push_back(1);
                    stuff.push_back(temp);
            }
            stuff.push_back(edge);
        return stuff;
        }
        //show the maze
        void show(){
            /*int row=stuff.size();
            vector<int> *col;
            col=&stuff[0];*/
            // �o��ؤo�ưȫݭ״_
            for(int f=0;f<stuff.size();f++){
                    for(int m=0;m<stuff[0].size();m++){
                        //cout<<"len="<<stuff[0].size();
                        //cout<<"col="<<m<<"row="<<f<<"matrix element ="<<stuff[m][f]<<endl;
                        cout<<stuff[f][m]<<" ";
                    }
                //cout<<"switch row";
                cout<<endl;
            }
        }
}mazevec;
//class route
typedef class route{
    private:
        vector<vector<int> > visited_coordinate_notsure;
        vector<vector<int> > dead_road;
        vector<vector<int> > correct_path;
        int road_walkable;

        //int passed_coordinate_rec(vector<vector<int>> coordi)

    public:
        mazevec mazevec;
        //the above are variables
            //�Y���T�N�ǤJ correct path

            //Letmove�i�঳���D
            void Letmove(int col, int row){
                //cout<<"add in correct road"<<endl;
                if(In_correct_path(col,row)==false){
                        correct_path.push_back({row,col});
                }
                else{}

                if(In_visited_notsure(col,row)==false){
                     visited_coordinate_notsure.push_back({row,col});
                }
                else{}
            }
            //�Y���~�[�J����
            void trace_back(int col, int row,vector<vector<int> > revised_maze){
                dead_road.push_back({row,col});
                correct_path.pop_back();
                row=correct_path.back()[0];
                col=correct_path.back()[1];
                judge(row, col,revised_maze);
                //�[�J�K���d�ݡA�Y���¦����hcallself
            }
            //�ݦ��L�Q�O�Jcorrect_road
            bool In_correct_path(int col, int row){
                int n=0;
                bool returnvalue;
                while(n!=correct_path.size()){
                    if((row==correct_path[n][0])&&(col==correct_path[n][1])){
                        returnvalue=true;
                        cout<<"is correct_path"<<endl;
                        break;
                    }
                    else if(n==correct_path.size()){
                        returnvalue=false;
                        cout<<"is not in correct_path"<<endl;
                        break;
                    }
                    n++;
                }
                return returnvalue;
            }
            //�ݦ��S�����X�L
            bool In_visited_notsure(int col, int row){
                int n=0;
                bool returnvalue;
                while(n!=visited_coordinate_notsure.size()){
                    if((row==visited_coordinate_notsure[n][0])&&(col==visited_coordinate_notsure[n][1])){
                        returnvalue=true;
                        //cout<<"is visited road"<<endl;
                        break;
                    }
                    else if(n==visited_coordinate_notsure.size()){
                        returnvalue=false;
                        cout<<"is brand new road"<<endl;
                        break;
                    }
                    n++;
                }
                return returnvalue;
            }
            //�ݬO���O���Q�O�W����
            bool In_dead_road(int col, int row){
                int k=0;
                bool returnvalue;
                if(dead_road.empty()==true){
                        //cout<<"dead road list is empty"<<endl;
                        returnvalue=false;
                }
                else{
                    //cout<<"array size = "<<dead_road.size()<<endl;
                    while(k!=dead_road.size()){
                        //cout<<"( "<<col<<","<<row<<" )"<<"( "<<dead_road[k][1]<<","<<dead_road[k][0]<<" )"<<endl;
                        if((row==dead_road[k][0])&&(col==dead_road[k][1])){
                            //cout<<"in dead road"<<endl;
                            returnvalue=true;
                            break;
                        }
                        else if(k==dead_road.size()){
                            //cout<<"not in dead road"<<endl;
                            returnvalue=false;
                            break;
                        }
                        else{
                            //cout<<"keep searching"<<endl;
                            k++;
                            //continue;
                        }
                    }
                //�d�ݰj��O�_�]��~��
                //cout<<"else run through ? test"<<endl;
                }
            return returnvalue;
            }
            //�K���d��
            void judge(int row, int col,vector<vector<int> > revised_maze){
                road_walkable=0;
                //cout<<revised_maze[row][col]<<"kkk"<<"in loop";
                //cout<<"===============================judge start================================="<<endl;
                //����o��A�Yjudge�X�y�Цb�D�������Ncall Letmove�Avisited�P��visit���H��visit�u���i�氻�d�C
                if((row==revised_maze.size()-2)&&(col==revised_maze[0].size()-2)){
                    correct_path.push_back({row,col});
                    //cout<<"well done !! you finish the map"<<endl;
                    for(int f=0;f<correct_path.size();f++){
                        cout<<correct_path[f][0]<<" "<<correct_path[f][1]<<endl;
                    }

                }
                else{
                    //cout<<"kkk"<<"in loop"<<endl;
                    //���_�Ӥ@�j��
                    for(int p=-1;p<=1;p++){
                        for(int i=-1;i<=1;i++){
                            if((i==0)&&(p==0)){}
                            else{
                                //cout<<"need judge"<<row+p<<col+i<<endl;
                                cout<<endl;
                                //�W�����Ѽg�F�����N���L�F
                                if(revised_maze[row+p][col+i]==0){
                                    //cout<<"( "<<col+i<<","<<row+p<<" )"<<"this road is walkable"<<endl;
                                    road_walkable++;
                                }
                                //�Y�[���y�ФW������1�h�p�J�����W��
                                else if((revised_maze[row+p][col+i]==1)&&(In_dead_road(col+i,row+p)==false)){
                                    //cout<<"( "<<col+i<<","<<row+p<<" )"<<"check dead road and pushed"<<endl;
                                    dead_road.push_back({row+p,col+i});
                                }
                                else if((revised_maze[row+p][col+i]==1)&&(In_dead_road(col+i,row+p)==true)){
                                    //cout<<"this dead road is met, we then do nothing"<<endl;
                                }
                                else{
                                    //cout<<"uncertain state"<<endl;
                                }

                            }
                        }
                    //cout<<endl;
                    }
                    //cout<<"check fin"<<endl;
                    for(int g=-1;g<=1;g++){
                        for(int h=-1;h<=1;h++){
                                if((g==0)&&(h==0)){}
                                else{
                                    //�Y�O�����h���^��
                                        if (road_walkable==1&&(col!=1&&row!=1)){
                                            //�ݭntraceback�o�� self call �٬O�~��call
                                            cout<<"( "<<col<<","<<row<<" )"<<"meet deadroad"<<endl;
                                            trace_back(col,row,revised_maze);
                                        }
                                    //�Y���O�h�b�s�y�Э��s�P�_
                                        else if((road_walkable>=2)||(road_walkable==1&&(col==1&&row==1))){
                                                cout<<endl;
                                                //�W�����Ѵ���]���L�F
                                                //int road_check=road_walkable;
                                                //����ťզA�靈���L����
                                                //�P�_�ҿ���O�_�����X�L
                                                if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==false)){
                                                    //cout<<"( "<<col+g<<","<<row+h<<" )"<<"brand new road lets move!!"<<endl;
                                                    //�ո���������m
                                                    //���ܡGcorrext road�̭��S���~�sbrand new ��~~
                                                    Letmove(col,row);
                                                    judge(row+h,col+g,revised_maze);
                                                }
                                                else if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==true)&&(road_walkable>2)){
                                                    //�Y�D�̫�@�ӿ�ܪ��ո��h�����L
                                                    cout<<"( "<<col+g<<","<<row+h<<" )"<<"spared visited road"<<endl;
                                                    road_walkable--;
                                                }
                                                else if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==true)&&(road_walkable==2)){
                                                    //�H���X�L�n�|������̫�O�̫�@���~����m
                                                    cout<<"( "<<col+g<<","<<row+h<<" )"<<"choose visited road !!"<<endl;
                                                    Letmove(col,row);
                                                    judge(row+h,col+g,revised_maze);
                                                }

                                        }
                                }
                            }
                        }//�P�_��
                }
            }
    }route;

int main(){
    mazevec mazevec;
    route route;
    int col, row;
    vector<vector<int> > *main_map;
    //cout<<"please key in array size:"<<endl;
    //cout<<"key in column numbers:";
    cin>>col;
    //cout<<"key in row numbers:";
    cin>>row;
    mazevec.build_maze(col,row);
    //mazevec.show();
    //cout<<mazevec.stuff[1][1]<<endl;
    route.judge(1,1,mazevec.stuff);
    //���Ѹոն�vector�i�hfunction��
    return 0;
}
