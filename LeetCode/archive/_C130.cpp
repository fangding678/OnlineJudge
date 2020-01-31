#include <iostream>
#include <vector>

using namespace std;

//Runtime Error
class Solution {
private:
    int len1, len2;
public:
    void solve(vector<vector<char>>& board) {
        len1 = board.size();
        if(len1 <= 2) {
            return ;
        }
        len2 = board[0].size();
        if(len2 <= 2) {
            return ;
        }
        int i, j;
        for(i=0; i<len1; ++i) {
            if(board[i][0] == 'O') {
                DFS(board, i, 0);
            }
            if(board[i][len2-1] == 'O') {
                DFS(board, i, len2-1);
            }
        }
        for(j=1; j<len2-1; ++j) {
            if(board[0][j] == 'O') {
                DFS(board, 0, j);
            }
            if(board[len1-1][j] == 'O') {
                DFS(board, len1-1, j);
            }
        }
        for(i=0; i<len1; ++i) {
            for(j=0; j<len2; ++j) {
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
    void DFS(vector<vector<char>>& board, int i, int j){
        board[i][j] = 'T';
        if(i>=1 && board[i-1][j] == 'O') {
            DFS(board, i-1, j);
        }
        if(i<len1-1 && board[i+1][j] == 'O') {
            DFS(board, i+1, j);
        }
        if(j>=1 && board[i][j-1] == 'O') {
            DFS(board, i, j-1);
        }
        if(j<len2-1 && board[i][j+1] == 'O') {
            DFS(board, i, j+1);
        }
    }
};

class Solution1 {
public:
	void solve(vector<vector<char>>& board) {
        int i,j;
        int row=board.size();
        if(!row)
        	return;
        int col=board[0].size();

		for(i=0;i<row;i++){
			check(board,i,0,row,col);
			if(col>1)
				check(board,i,col-1,row,col);
		}
		for(j=1;j+1<col;j++){
			check(board,0,j,row,col);
			if(row>1)
				check(board,row-1,j,row,col);
		}
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='O')
					board[i][j]='X';
		for(i=0;i<row;i++)
			for(j=0;j<col;j++)
				if(board[i][j]=='1')
					board[i][j]='O';
    }
	void check(vector<vector<char> >&vec,int i,int j,int row,int col){
		if(vec[i][j]=='O'){
			vec[i][j]='1';
			if(i>1)
				check(vec,i-1,j,row,col);
			if(j>1)
				check(vec,i,j-1,row,col);
			if(i+1<row)
				check(vec,i+1,j,row,col);
			if(j+1<col)
				check(vec,i,j+1,row,col);
		}
	}
};

int func()
{
    cout << "Hello world!" << endl;
    return 0;
}
