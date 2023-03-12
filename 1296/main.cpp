#include <iostream>
#include <cinttypes>

using namespace std;

int main(){
    
    size_t  N;

    scanf("%d", &N);

    int64_t num;
    
    int64_t ans = 0;
    int64_t sum = 0;

    for (int16_t i = 0; i < N; ++i){
        scanf("%d",  &num);
        sum += num;
        sum < 0 ? sum = 0 : ans = max(sum, ans);
    }

    cout << ans << endl;
    

}