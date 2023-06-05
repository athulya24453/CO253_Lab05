#include <stdio.h>
#include <stdlib.h>

int ans(int magic[],int m_size, int dist[], int d_size){
    int* m = malloc(2*m_size * sizeof(int));
    int* d = malloc(2*d_size * sizeof(int));

    for (int i=0;i<m_size;i++){
        m[i]=magic[i];
        m[m_size+i] = magic[i];
    }

    for (int j=0;j<m_size;j++){
        d[j]=dist[j];
        d[m_size+j] = dist[j];

    }

    for (int x=0;x<m_size;x++){
        int magic_rem = magic[x];
        int count = 0;
        for (int y=x;y<=m_size+x;y++){
            if (magic_rem<d[y]){
                break;
            }

            else{
                magic_rem = magic_rem-d[y]+m[y+1];
                count++;
            }

            if (count == m_size){
                return x;
            }

            }
        }
    return -1;
}

int main()
{
    int m_arr[4];
    for (int i=0; i<4;i++){
        scanf("%d", &m_arr[i]);
    }

    int d_arr[4];
    for (int i=0; i<4;i++){
        scanf("%d", &d_arr[i]);
    }

    //ans(m_arr,4,d_arr,4);
    int a = ans(m_arr,4,d_arr,4);
    printf("%d", a);

    return 0;
}
