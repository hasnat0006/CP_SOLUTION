if (a > mood and d > mood)
            ans = mood + mood + 1;
        else if(a> mood and d <= mood)
            ans = mood + mood;
        else if(a>mood and d==0)
            ans = mood;
        else if(a<=mood and d > mood)
        {
            ans += mood;
            ans += a;
            mood = mood - a;
            ans += mood + 1;
        }
        else if(a<=mood and d <= mood)
        {
            ans += mood;
            ans += a;
            mood = mood - a;
            ans += mood;
        }
        else if(a<=mood and d == 0)
        {
            ans += mood;
            ans += a;
            mood = mood - a;
        }