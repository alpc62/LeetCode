impl Solution
{
    pub fn longest_palindrome(s: String) -> String
    {
        let mut st = 0;
        let mut ed = 0;
        let mut maxl = 0;
        let n = s.len();
        for i in 0..n
        {
            let mut j = n - 1;

            while j >= i + maxl
            {
                let l = (j - i + 1) / 2;
                let mut is_palindrome = true;

                for k in 0..l
                {
                    if s.as_bytes()[i + k] != s.as_bytes()[j - k]
                    {
                        is_palindrome = false;
                        break;
                    }
                }

                if (is_palindrome)
                {
                    st = i;
                    ed = j + 1;
                    maxl = ed - st;
                    break;
                }

                j -= 1;
            }
        }

        return String::from(&s[st..ed]);
    }
}