#include<iostream>
#include<vector>

using namespace std;
/*
いま、神の恵みで高橋くんにお金が与えられます。
神は高橋くんに 
2
 つの金額を提示します。
正直者の高橋くんは、常に大きな金額を選択します。
そこで、与えられた 
2
 つの整数のうち、大きい方の値を出力するプログラムを書いてください。
*/

int main(){
    int x, y;
    cin >> x >> y;
    if(x >= y) cout << x << endl;
    else cout << y << endl;
    return 0;
}