#include <bits/stdc++.h>
using namespace std;
struct node
{
	float x,y,z;
};
node move_point(node now)
{
	node ans;
	ans.x=now.x+0.005434f;
	ans.y=now.y+0.005434f;
	ans.z=now.z+0.005434f;
	return ans;
}

void get_sq(node a,node b,node c,node d,vector<node>& G)
{
	G.push_back(a);
	G.push_back(b);
	G.push_back(c);
	G.push_back(d);
}
vector<node> tot_vertex;
vector<node> tot_vertex2;
int main (){
	fstream f;
	string s;
	f.open ("hair.pbrt");
	int cntline = 0;
//	for (int i = 1 ; i <= 10 ; i ++){
	while (getline (f, s)){
		cntline ++;
		stringstream t(s);
		string a; float b[12];
		int cnt = 10;
		while (cnt --) t >> a;
		for (cnt = 0 ; cnt < 12; cnt ++){
			t >> b[cnt];
		}
		for (cnt = 0; cnt < 12; cnt+=3) {
			//cout << b[cnt] << ' ';
			node mesh_data;
			mesh_data.x = b[cnt];
			mesh_data.y = b[cnt + 1];
			mesh_data.z = b[cnt + 2];
			tot_vertex.push_back(mesh_data);
		}
		
	}
	f.close();
	
	for(int i=0;i<tot_vertex.size();i+=4)
	{
		get_sq(tot_vertex[i],move_point(tot_vertex[i]),move_point(tot_vertex[i+1]),tot_vertex[i+1],tot_vertex2);
		get_sq(tot_vertex[i+1],move_point(tot_vertex[i+1]),move_point(tot_vertex[i+2]),tot_vertex[i+2],tot_vertex2);
		get_sq(tot_vertex[i+2],move_point(tot_vertex[i+2]),move_point(tot_vertex[i+3]),tot_vertex[i+3],tot_vertex2);
	}
	//cout << cntline << endl;
	ofstream OutFile("curve_big.obj");
	for (int i = 0; i < tot_vertex2.size(); i++)
	{
		OutFile << "v " << tot_vertex2[i].x << " " << tot_vertex2[i].y << " " << tot_vertex2[i].z << "\n";
		//if(i>0)
			//OutFile << "l " << i << " " << i+1 << endl;
		
	}
	int num1=1;
	int num2=2;
	int num3=3;
	int num4=4;
	for (int i = 0; i < tot_vertex2.size(); i+=4)
	{
		OutFile << "f "<<num1<<" "<<num2<<" "<<num3<<" "<<num4<<"\n";
		num1+=4; num2+=4; num3+=4; num4+=4;
    }
	//OutFile << "v " << line_para[0] << " " << line_para[1] << " " << line_para[2] << endl << "v " << line_para[3] << " " << line_para[4] << " " << line_para[5] << endl;  //把字符串内容"This is a Test!"，写入Test.txt文件
 
	OutFile.close(); 
} 
