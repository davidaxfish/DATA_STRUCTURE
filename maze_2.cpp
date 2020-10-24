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
            //這邊似乎沒有真正意義上輸好矩陣
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
            // 這邊尺寸事務待修復
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
            //若正確就納入 correct path

            //Letmove可能有問題
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
            //若錯誤加入死路
            void trace_back(int col, int row,vector<vector<int> > revised_maze){
                dead_road.push_back({row,col});
                correct_path.pop_back();
                row=correct_path.back()[0];
                col=correct_path.back()[1];
                judge(row, col,revised_maze);
                //加入八方位查看，若依舊死路則callself
            }
            //看有無被記入correct_road
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
            //看有沒有拜訪過
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
            //看是不是曾被記上死路
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
                //查看迴圈是否跑到外面
                //cout<<"else run through ? test"<<endl;
                }
            return returnvalue;
            }
            //八方位查看
            void judge(int row, int col,vector<vector<int> > revised_maze){
                road_walkable=0;
                //cout<<revised_maze[row][col]<<"kkk"<<"in loop";
                //cout<<"===============================judge start================================="<<endl;
                //打到這邊，若judge出座標在非死路中就call Letmove，visited與未visit中以未visit優先進行偵查。
                if((row==revised_maze.size()-2)&&(col==revised_maze[0].size()-2)){
                    correct_path.push_back({row,col});
                    //cout<<"well done !! you finish the map"<<endl;
                    for(int f=0;f<correct_path.size();f++){
                        cout<<correct_path[f][0]<<" "<<correct_path[f][1]<<endl;
                    }

                }
                else{
                    //cout<<"kkk"<<"in loop"<<endl;
                    //夾起來一大串
                    for(int p=-1;p<=1;p++){
                        for(int i=-1;i<=1;i++){
                            if((i==0)&&(p==0)){}
                            else{
                                //cout<<"need judge"<<row+p<<col+i<<endl;
                                cout<<endl;
                                //上面註解寫了側茲就不過了
                                if(revised_maze[row+p][col+i]==0){
                                    //cout<<"( "<<col+i<<","<<row+p<<" )"<<"this road is walkable"<<endl;
                                    road_walkable++;
                                }
                                //若觀測座標上元素為1則計入死路名單
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
                                    //若是死路則往回走
                                        if (road_walkable==1&&(col!=1&&row!=1)){
                                            //看要traceback這裡 self call 還是外部call
                                            cout<<"( "<<col<<","<<row<<" )"<<"meet deadroad"<<endl;
                                            trace_back(col,row,revised_maze);
                                        }
                                    //若不是則在新座標重新判斷
                                        else if((road_walkable>=2)||(road_walkable==1&&(col==1&&row==1))){
                                                cout<<endl;
                                                //上面註解測資也不過了
                                                //int road_check=road_walkable;
                                                //先選空白再選有走過的路
                                                //判斷所選方位是否有拜訪過
                                                if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==false)){
                                                    //cout<<"( "<<col+g<<","<<row+h<<" )"<<"brand new road lets move!!"<<endl;
                                                    //白路直接換位置
                                                    //提示：corrext road裡面沒有才叫brand new 唷~~
                                                    Letmove(col,row);
                                                    judge(row+h,col+g,revised_maze);
                                                }
                                                else if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==true)&&(road_walkable>2)){
                                                    //若非最後一個選擇的白路則先跳過
                                                    cout<<"( "<<col+g<<","<<row+h<<" )"<<"spared visited road"<<endl;
                                                    road_walkable--;
                                                }
                                                else if((In_dead_road(col+g,row+h)==false)&&(In_visited_notsure(col+g,row+h)==true)&&(road_walkable==2)){
                                                    //以拜訪過要ㄍㄧㄥ到最後是最後一條才換位置
                                                    cout<<"( "<<col+g<<","<<row+h<<" )"<<"choose visited road !!"<<endl;
                                                    Letmove(col,row);
                                                    judge(row+h,col+g,revised_maze);
                                                }

                                        }
                                }
                            }
                        }//判斷式
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
    //明天試試傳vector進去function鍾
    return 0;
}
