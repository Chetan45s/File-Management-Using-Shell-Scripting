#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fo(i, z, n) for (int i = z; i < N; i++)
#define Fo(i, k, n) for (int i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define mod 1000000007
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << ", " << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
#define endl "\n"
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;



#define N 8

void createPuzzle(int board[][N], int* state) { 
	srand(time(0)); 
	fo(i,0,n) { 
		state[i] = rand() % N; 
		board[state[i]][i] = 1; 
	} 
} 
void printBoard(int board[][N]) { 
	fo(i,0,n) { 
		cout << " "; 
		fo(j,0,n) { 
			if(board[i][j] == 1){
				cout << "Q" << " ";
			} 
			else{
				cout << "_" << " ";
			}
		} 
		cout << "\n"; 
	} 
} 
bool compareStates(int* state1, int* state2) { 
	fo(i,0,n) { 
		if (state1[i] != state2[i]) { 
			return false; 
		} 
	} 
	return true; 
} 
void fill(int board[][N], int value) { 
	fo(i,0,n) { 
		fo(j,0,n) { 
			board[i][j] = value; 
		} 
	} 
} 
int attacks(int board[][N], int* state) { 
	int count = 0; 
	int row, col; 
	fo(i,0,n) { 
		row = state[i], col = i - 1; 
		while (col >= 0 && board[row][col] != 1) { 
			col--; 
		} 
		if (col >= 0 && board[row][col] == 1) { 
			count++; 
		} 
		row = state[i], col = i + 1; 
		while (col < N && board[row][col] != 1) { 
			col++; 
		} 
		if (col < N && board[row][col] == 1) { 
			count++; 
		} 
		row = state[i] - 1, col = i - 1; 
		while (col >= 0 && row >= 0 && board[row][col] != 1) { 
			col--; 
			row--; 
		} 
		if (col >= 0 && row >= 0 && board[row][col] == 1) { 
			count++; 
		} 
		row = state[i] + 1, col = i + 1; 
		while (col < N && row < N && board[row][col] != 1) { 
			col++; 
			row++; 
		} 
		if (col < N && row < N && board[row][col] == 1) { 
			count++; 
		} 
		row = state[i] + 1, col = i - 1; 
		while (col >= 0 && row < N && board[row][col] != 1) { 
			col--; 
			row++; 
		} 
		if (col >= 0 && row < N && board[row][col] == 1) { 
			count++; 
		} 
		row = state[i] - 1, col = i + 1; 
		while (col < N && row >= 0 && board[row][col] != 1) { 
			col++; 
			row--; 
		} 
		if (col < N && row >= 0 && board[row][col] == 1) { 
			count++; 
		} 
	} 
	return (int)(count / 2); 
} 
void gBoard(int board[][N], int* state) { 
	fill(board, 0); 
	fo(i,0,n) { 
		board[state[i]][i] = 1; 
	} 
} 
void copyState(int* state1, int* state2) { 
	fo(i,0,n) { 
		state1[i] = state2[i]; 
	} 
} 
void states(int board[][N],int* state) { 
	int opb[N][N]; 
	int ops[N]; 
	copyState(ops, state); 
	gBoard(opb, ops); 
	int opo = attacks(opb, ops); 
	int nb[N][N]; 
	int ns[N]; 
	copyState(ns, state); 
	gBoard(nb,ns); 

	fo(i,0,n) { 
		fo(j,0,n) { 
			if (j != state[i]) { 
				ns[i] = j; 
				nb[ns[i]][i] = 1; 
				nb[state[i]][i] = 0; 
				int temp = attacks(nb, ns); 
				if (temp <= opo) { 
					opo = temp; 
					copyState(ops,ns); 
					gBoard(opb, ops); 
				} 

				nb[ns[i]][i] = 0; 
				ns[i] = state[i]; 
				nb[state[i]][i] = 1; 
			} 
		} 
	} 
	copyState(state, ops); 
	fill(board, 0); 
	gBoard(board, state); 
} 
void hillClimbing(int board[][N], int* state) { 
	int nb[N][N] = {}; 
	int ns[N]; 

	copyState(ns, state); 
	gBoard(nb, ns); 

	do { 
		copyState(state, ns); 
		gBoard(board, state); 
		states(nb, ns); 

		if (compareStates(state,ns)) { 
			printBoard(board); 
			break; 
		} 
		else if (attacks(board, state) == attacks(nb,ns)) { 
			ns[rand() % N] = rand() % N; 
			gBoard(nb,ns); 
		} 
	} while (true); 
} 

int32_t main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int state[N] = {}; 
	int board[N][N] = {}; 
	createPuzzle(board, state); 
	hillClimbing(board, state); 
	return 0; 
}

/*

Output : 

 _ _ _ Q _ _ _ _
 _ _ _ _ _ Q _ _
 Q _ _ _ _ _ _ _
 _ _ _ _ Q _ _ _
 _ Q _ _ _ _ _ _
 _ _ _ _ _ _ _ Q
 _ _ Q _ _ _ _ _
 _ _ _ _ _ _ Q _

 */