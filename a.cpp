int a[5] = {1,2,5,7,9};
int* pos = lower_bound( a, a+n, key );
vector<int> v (a, a+5);
vector<int>::iterator iter;
iter = lower_bound( v.begin(), v.end(), key );
int value = *iter;    // value = *pos;
return 的型態是指標/iterator，代表找到的位置
如果找不到，會回傳容器尾端的位置.end()
