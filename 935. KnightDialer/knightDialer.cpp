    int knightDialer(int N) {
        if(N == 1) return 10;
        int a[10];
        a[0] = 2;
        a[1] = 2;
        a[2] = 2;
        a[3] = 2;
        a[4] = 3;
        a[5] = 0;
        a[6] = 3;
        a[7] = 2;
        a[8] = 2;
        a[9] = 2;
        long limit = 1000000000+7;
        int t[10];
        for(int i = 3; i <= N; i++){
            t[0] =  (long)(a[4] + a[6]) % limit;
            t[1] =  (long)(a[6] + a[8]) % limit;
            t[2] =  (long)(a[7] + a[9]) % limit;
            t[3] =  (long)(a[4] + a[8]) % limit;
            t[4] =  (long)(((long)(a[3] + a[9]) % limit) + a[0]) % limit;
            t[5] =  0;
            t[6] =  (long)(((long)(a[1] + a[7]) % limit) + a[0]) % limit;
            t[7] =  (long)(a[2] + a[6]) % limit;
            t[8] =  (long)(a[1] + a[3]) % limit;
            t[9] =  (long)(a[4] + a[2]) % limit;
            for(int i = 0; i < 10; i++) a[i] = t[i];
        }

        long answer = 0;
        for(int i = 0; i < 10; i++){
            answer = (answer + a[i]) % limit;
        }
        return answer;        
    }
