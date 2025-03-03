//qwerty
//qwerty2.0
void SelectSort(struct Student students[N]){
    for (int i=0;i<N;i++){
        int k = i;
        for (int j=i+1;j<N;j++){
            if (students[k].sum < students[j].sum){
                k=j;}}
    struct Student stud=students[i];
    students[i]=students[k];
    students[k]=stud;}
}
