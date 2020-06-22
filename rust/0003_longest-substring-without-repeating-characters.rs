impl Solution
{
    pub fn length_of_longest_substring(s: String) -> i32
    {
        let n = s.len();
        let mut res = 0;
        let mut flag: [bool; 256] = [false; 256];
        let mut st = 0;
        let mut ed = 0;
        let mut ed_ch = 0;
        while ed < n
        {
            while ed < n
            {
                ed_ch = s.as_bytes()[ed] as usize;
                if flag[ed_ch]
                {
                    break;
                }

                flag[ed_ch] = true;
                ed += 1;
            }

            if ed - st > res
            {
                res = ed - st;
            }

            if ed < n
            {
                while st < ed
                {
                    let st_ch = s.as_bytes()[st] as usize;
                    flag[st_ch] = false;
                    st += 1;
                    if st_ch == ed_ch
                    {
                        break;
                    }
                }
            }
        }

        return res as i32;
    }
}
