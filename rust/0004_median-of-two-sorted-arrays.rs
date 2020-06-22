impl Solution
{
    pub fn find_median_sorted_arrays(a: Vec<i32>, b: Vec<i32>) -> f64
    {
        let mut c = Vec::new();
        let m = a.len();
        let n = b.len();
        let all = m + n;
        let mut i = 0;
        let mut j = 0;

        while i < m && j < n
        {
            if (a[i] < b[j])
            {
                c.push(a[i]);
                i += 1;
            }
            else
            {
                c.push(b[j]);
                j += 1;
            }
        }

        while i < m
        {
            c.push(a[i]);
            i += 1;
        }

        while j < n
        {
            c.push(b[j]);
            j += 1;
        }

        if all % 2 == 0
        {
            return (c[all / 2 - 1] + c[all / 2]) as f64 / 2.0;
        }
        else
        {
            return c[all / 2] as f64;
        }
    }
}
