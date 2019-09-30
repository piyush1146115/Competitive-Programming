#include<bits/stdc++.h>
using namespace std;
#define MAX 30005
string s;
int ara[MAX];
struct st{
int op, cl;
}tree[MAX * 4];

st combine(int left, int right)
{
    st ret;
    ret.op = max(0,tree[left].op - tree[right].cl) + tree[right].op;
    ret.cl = max(0,tree[right].cl - tree[left].op) + tree[left].cl;
    return ret;
}

st make_data(int val)
{
    st ret;
    ret.op = val;
    ret.cl = 1 - val;
    return ret;
}

void build(int node, int b, int e)
{
    if(b == e){
        tree[node] = make_data(ara[b]);
        return;
    }

    int mid = (b+e)/2;
    build(node*2, b, mid);
    build(node*2+1, mid + 1, e);
    tree[node] = combine(node*2, node*2+1);
 //   cout << b << "  " << e << " " << tree[node].op << " " << tree[node].cl << endl;
}

void update(int node, int b, int e, int pos)
{
    if(e < pos || b > pos){
        return;
    }
    if(b >= pos && e <= pos){
        tree[node] = make_data(1 - tree[node].op);
        return;
    }

    int mid = (b+e)/2;
    update(node *2, b, mid, pos);
    update(node *2+1, mid + 1, e, pos);
    tree[node] = combine(node*2, node*2+1);
}

int main()
{
    int test = 10, n, q, k;

    for(int tc = 1; tc <= test; tc++){
        scanf("%d", &n);
        cin >> s;
        for(int i = 0; i < s.size(); i++ ){
            if(s[i] == '('){
                ara[i + 1] = 1;
               }
               else{
                ara[i + 1] = 0;
               }
        }
        build(1, 1, n);
        scanf("%d", &q);
        printf("Test %d:\n",tc);

        while(q--){
            scanf("%d", &k);
            if(k > 0){
                update(1, 1, n, k);
            }else{
            //    cout << tree[1].op << " "<<  tree[1].cl << endl;
                if(tree[1].op == tree[1].cl && tree[1].cl== 0){
                    printf("YES\n");
                }else{
                    printf("NO\n");
                }
            }
        }
    }
}
