impl Solution
{
    pub fn convert(s: String, num_rows: i32) -> String
    {
        if num_rows <= 1
        {
            return s;
        }

        let nr = num_rows as usize;
        let mut res = String::new();
        let n = s.len();
        let round = nr * 2 - 2;

        for r in 0..nr
        {
            let mut i = r;

            if i == 0 || i == nr -1
            {
                while i < n
                {
                    res.push(s.as_bytes()[i] as char);
                    i += round;
                }
            }
            else
            {
                let mut step = round - r * 2;
                while i < n
                {
                    res.push(s.as_bytes()[i] as char);
                    i += step;
                    step = round - step;
                }
            }
        }

        return res;
    }
}
