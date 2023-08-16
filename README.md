# Baekjoon_CodingTest

### 백준 코딩 테스트 문제 풀이- 핵심 알고리즘(코드는 순서대로 되어 있지는 않음)

BOJ4375

    while(true){
        if(start%num== 0)return count;
        start=start*10+1;
        count++;
        start %= num;
    }

start(1, 11, 111 ...)가  num과 나누어 떨어지지 않는다면 start가 증가되고 나서 start %= num을 해주는 사고가 중요.

BOJ17427

    long long ans = 0;
    for(int i = 1; i <= N; i++){
        ans += (N/i) *i;
    }

1~N까지 약수들의 합을 다 더한 것은 i(약수)에 (N/i)등장 횟수를 곱하여 더해준다는 사고가 중요.

BOJ17425

    long long dp[1000001];
    /* 약수들의 합을 저장 */
    for(int i = 1; i <= 1000001; i++){
        for(int j = i; j <= 1000001; j+=i){
            dp[j] += i;
        }
    }
    /* 이전 약수의 합 까지 저장 */
    for(int i = 2; i <= 1000001; i++){
        dp[i] += dp[i-1];
    }

    for(int j=0; j<T; j++){
        scanf("%d", &N);
        printf("%lld\n",dp[N]);
    }

17427번의 알고리즘을 테스트 케이별로 반복하면 시간 초과 문제 발생. 따라서 이번 문제는 미리 배열(dp)에 약수들의 합을 전부 저장하고 해당 배열에서 가져오는 방식으로 시간 초과 문제를 해결하는 사고가 중요. + cin,cout를 사용하면 시간 초과 문제가 발생하는 것을 보아, scanf,printf가 더 효율적이라고 생각함.


BOJ6588

    //에라토스테네스의 체 만들어 놓기
    for(int i = 2; i<=1000000;i++){
       dp[i]=i;
    }
    for(int i = 2; i<=1000000;i++){
        if(dp[i]==0)continue;
        for(int j=2*i;j<=1000000;j+=i){
            dp[j]=0;
        }
    } 

    for(long long i=N-1; i>1;i--){
            if(N == dp[i] + dp[N-i]){
                printf("%lld = %lld + %lld\n", N,dp[N-i],dp[i]);
                break;
            }
    }

에라토스테네스의 체(소수 배열)를 만드는 것이 핵심 사고

BOJ2309

    #include <algorithm>
    sort(h,h+9);

    //전체에서 2개 빼서 100이 되는지 확인
    for(int i = 0; i <8; i++){
        for(int j = i+1; j<9; j++){
            if(sum - h[i]-h[j]==100){
                //output
                for(int k=0;k<9;k++){
                    if(k==i || k==j)continue;
                    printf("%d\n",h[k]);
                }
                return 0;
            }
        }
    }

sort함수의 사용, 7개를 더하는 방식보다 9개 중 2개를 뺴는 사고가 중요.

BOJ3085

    //find row case
    for(int i=0;i<N;i++){
        for(int j=0;j<N-1;j++){
            //swap
                swap(b[i][j],b[i][j+1]);
            //check
                find_max();
            //return
                 swap(b[i][j],b[i][j+1]);
            }
    }

algorithm import후 swap함수의 사용, 행(열도 동일 방식)을 기준으로 바꾼다음 최대값 찾고 다시 원상태 복구

BOJ1476

단순 연산이어서 기타 메모 없음

BOJ1107

    //일단은 + 버튼 만으로 갈 수 있는 횟수로 초기화
    count=abs(n-100);
    //브루트 포스 알고리즘
    for(int i=0;i<=1000000;i++){
        int c=i;
        //i번 채널로 이동할 수 있는지
        int len=check(c);
        if(len>0){
            //i번 채널에서 n(타겟 채널로) + 버튼 만으로 가는 횟수
            int press=abs(c-n);
            //두개 비교후 작은거로 초기화
            if(count>press+len){
                count=press+len;
            }
        }
    }

해당 알고리즘의 흐름을 이해하는 것이 중요


BOJ14500-***

    int dir[4][2] = { {0,1} ,{0,-1},{1,0},{-1,0} };

    void dfs(int r, int c, int depth, int sum) {
	if (depth == 3) {
		answer = max(answer, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nR = r + dir[i][0];
		int nC = c + dir[i][1];
		if (!isInside(nR, nC))continue;
		if (visited[nR][nC])continue;
		visited[nR][nC] = true;
		dfs(nR, nC, depth + 1, sum + graph[nR][nC]);
		visited[nR][nC] = false;
	}
    }

DFS활용, 2차원 배열의 dfs를 위해 방향 배열인 dir 사용이 중요. shape함수들은 ㅗ모양을 돌려가며 비교하는 것

BOJ1748

    for (int i = 1; i <= n; i *= 10) 
		result += n - i + 1;
    //n=120인 경우: 120(1의 자리 개수)+111(10의자리 개수)+21(100의 자리 개수)

단순 구현 문제


BOJ9095

    for(int i=3;i<11;i++){
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    }

미리 규칙을 파악해서 배열에 값을 저장하는 것이 핵심

BOJ15654

    void dfs(int depth){
    if(depth==m){
        for(int i=0; i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int j=0;j<n;j++){
        if(visited[j])continue;
        visited[j]=1;
        arr[depth]=num[j];
        dfs(depth+1);
        visited[j]=0;
    }
    }

dfs알고리즘의 응용

BOJ15655

    void dfs(int depth,int start){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<arr[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=start;i<n;i++){
        if(visited[i])continue;
        visited[i]=1;
        arr[depth]=num[i];
        dfs(depth+1,i);
        visited[i]=0;
    }

    }

15654번에 + 시작 지점(start)를 지정해주는 것으로 응용

BOJ15656

    void dfs(int depth){
    if(depth==m){
        for(int i=0;i<m;i++){
            cout<<num[i]<<' ';
        }
        cout<<'\n';
        return;
    }
    for(int i=0;i<n;i++){
        num[depth]=arr[i];
        dfs(depth+1);
    }
    }

15654번에 visited를 제외한 버전

BOJ15657

    void dfs(int start, int depth)
    {
    if (depth == m)
    {
        for (int i = 0; i < m; i++)
        {
            cout << result[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for (int i = start; i < n; i++)
    {
        result[depth] = arr[i];
        dfs(i, depth + 1);

    }
    }

15655번에 visited를 제외한 버전

BOJ6064

    // 최대 공약수
    int gcd(int a, int b)
    {
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
    }
    // 최소 공배수
    int lcm(int a, int b)
    {
    return a * b / gcd(a, b);
    }

    int year()
    {
    int limit = lcm(m, n);
    int j;
    for (j = x; j <= limit; j += m)
    {
        int temp = (j % n == 0) ? n : j % n;
        if (temp == y)
        {
            return j;
        }
    }
    return -1;
    }

최대 공약수, 최소 공배수 알고리즘 + 규칙 찾기 복습 필요

BOJ18290

BOJ1759

BOJ14501

BOJ14889

BOJ15661

BOJ2529

BOJ10972
