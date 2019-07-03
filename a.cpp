array版
int key = 3;
int a[5] = {1,2,5,7,9};
int* pos = lower_bound(a,a+n,key);
cout << *pos << endl;
//5
