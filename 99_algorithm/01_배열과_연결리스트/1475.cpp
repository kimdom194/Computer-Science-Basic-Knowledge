/* 
�ټ��̴� �������� ������ ���� �̻�Դ�. �ټ��̴� �ڱ� �� ��ȣ�� ���� �ö�ƽ ���ڷ� ���� ���̷��� �Ѵ�.

�ټ����� ���������� �ö�ƽ ���ڸ� �� ��Ʈ�� �Ǵ�. �� ��Ʈ���� 0������ 9������ ���ڰ� �ϳ��� ����ִ�. �ټ����� �� ��ȣ�� �־����� ��, �ʿ��� ��Ʈ�� ������ �ּڰ��� ����Ͻÿ�. (6�� 9�� ����� �̿��� �� �ְ�, 9�� 6�� ����� �̿��� �� �ִ�.)

�Է�
ù° �ٿ� �ټ����� �� ��ȣ N�� �־�����. N�� 1,000,000���� �۰ų� ���� �ڿ��� �Ǵ� 0�̴�.

���
ù° �ٿ� �ʿ��� ��Ʈ�� ������ ����Ѵ�.
*/

#include <bits/stdc++.h>

using namespace std;
int main(void){
    string roomNum;
    cin >> roomNum; // ���ȣ �Է�
    int roomlen = roomNum.length(); // ���ȣ ����
    string arrRoom[roomlen];
    
    for(int i = 0; i < roomlen; i++){ // �迭�� ���ȣ ����
        arrRoom[i] = roomNum.substr(i,1);
    }

    int cnt[10] = {0}; // ī��Ʈ ��� �Է�

    for(int i = 0; i < roomlen; i++){
        for(int j = 0; j < 10; j++){
            string k = to_string(j);
            if(k.compare(arrRoom[i]) == 0){ // ��ġ�ϸ� ī��Ʈ + 1
                    cnt[j] = cnt[j] + 1;
            }
        }
    }

    if((cnt[9]+cnt[6]) % 2 == 0){
        cnt[6], cnt[9] = (cnt[9]+cnt[6]) / 2;
    }else{
        cnt[6], cnt[9] = (cnt[9]+cnt[6]) / 2 + 1;
    }
    cout << *max_element(cnt, cnt+10) << endl; //�ƽ������� ��Ʈ�� ���
    
}