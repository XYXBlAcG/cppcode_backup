#include <cstdio>
int n, m;
const int N = 1e6 + 3;
struct Node
{
    int val;
    Node *nxt;
    Node *pre;
};

int main(){
    scanf("%d%d",&n,&m);
    // for (int i = 1; i <= n; i++){
    //     Node *p2;
    //     // int *p1 = new int(i);
        
    //     // scanf("%d",p2 -> p1 -> val);
    // }
    Node *head, *p, *now, *prev, *list;
    head = new Node; head -> val = -1; head -> nxt = NULL; head -> pre = NULL;
    now = head;
    // head = {-1,,};
    for (int i = 1; i <= n; i++){
        int tmp = 0;
        scanf("%d",&tmp);
        p = new Node; p -> val = tmp; p -> nxt = NULL;p -> pre = now;
        now -> nxt = p;
        now = p;
    }
    //
    for (int i = 1; i <= m; i++){
        //read
        now = head;
        char t1, spa;
        for (int j = 1; j <= 3; j++){
            scanf("%c",&t1);
        }
        scanf("%c",&spa);
        if (t1 == 'd'){
            int im = 0,xm = 0;
            scanf("%d%d",&im,&xm);
            now = head;
            for (int j = 1; j <= im; j++){
                now = now -> nxt;
                // tmpp = now -> next -> val;
            }
            
            // p -> nxt = now -> nxt; 
            // p -> nxt -> val = now -> nxt -> val;
            // now -> nxt -> pre = now -> pre;
            // now -> pre -> nxt = now -> nxt;
            now -> nxt -> val = xm;
            //in
            printf("method mod ");
        }else if(t1 == 's'){
            int im = 0,xm = 0;
            scanf("%d%d",&im,&xm);
            // Node *tmpp;
            now = head;
            for (int j = 1; j <= im; j++){
                now = now -> nxt;
                // tmpp = now -> next -> val;
            }
            // now = tmpp;

            now -> nxt -> pre -> val = xm;
            now -> nxt -> nxt = now -> nxt;
            now -> nxt -> val = xm;
            now -> nxt -> pre = now;
            printf("method ins ");
        }else if(t1 == 'l'){
            int im = 0;
            scanf("%d",&im);
            // Node *tmpp;
            now = head;
            for (int j = 1; j <= im; j++){
                now = now -> nxt;
                // tmpp = now -> next -> val;
            }
            // now = tmpp;
            now -> nxt -> pre = now -> pre;
            now -> pre -> nxt = now -> nxt;
            printf("method del ");
        }else if(t1 == 'e'){
            int im = 0;
            scanf("%d",&im);
            // Node *tmpp;
            now = head;
            for (int j = 1; j <= im; j++){
                now = now -> nxt;
                // tmpp = now -> next -> val;
            }
            printf("%d\n",now -> val);
            printf("method que ");
        }
        printf("完成 %d 次。\n",i);
    }
    // for (int i = 1; i <= m; i++){
    //     for (int j = 1; j <= 4; j++){
    //     order[j] = getchar();
    //     }
    //     if(order[1] == 'm'){//mod
    //     int im = 0, xm = 0;
    //         scanf("%d",&im);
    //         scanf("%d",&xm);
    //         list[im].val = xm;
    //     }else if(order[1] == 'i'){//ins
    //         int im = 0, xm = 0;
    //         scanf("%d",&im);
    //         scanf("%d",&xm);
    //         Node aim = {};
            
    //     }else if(order[1] == 'd'){//del
            
    //     }else{//que

    //     }
    // }
    return 0;
}