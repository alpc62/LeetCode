impl Solution
{
    pub fn reverse(x: i32) -> i32
    {
        let mut is_negative = false;
        let mut y32 = 0;
        let mut y64 = 0 as i64;
        let mut x32 = x;

        if x32 < 0
        {
            is_negative = true;
            x32 *= -1;
        }

        while x32 > 0
        {
            let n = x32 % 10;

            y32 = y32 * 10 + n;
            y64 = y64 * 10 + n as i64;
            x32 /= 10;
        }

        if is_negative
        {
            y32 *= -1;
            y64 *= -1;
        }

        if y32 as i64 != y64
        {
            y32 = 0;
        }

        return y32;
    }
}
