#include <bits/stdc++.h>
using namespace std;
int main()
{
    int mergulharam=0, voltaram= 0, dif = 0;
    cin >> mergulharam >> voltaram;
    
    int m_volt[voltaram];
    m_volt[0] = 0;
    for (int i = 0; i < voltaram; i++){
        cin >> m_volt[i];
    }
    
    if (mergulharam == voltaram){
        cout << "*"  << endl;
    }else{
        for(int x=1;x<=mergulharam;x++){
            for(int j = 0; j < voltaram;j++){
                if(x != m_volt[j]){
                    dif++;
                }
            }
            if (dif == voltaram){
                cout << x << " ";
                dif=0;
            }else{
                dif=0;
            }
            
        }
            
    }
    
    return 0;
}