// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution
{
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>>
    {
        if l1.is_none() && l2.is_none()
        {
            return None;
        }

        let mut s = 0;
        let mut a = &l1;
        let mut b = &l2;
        let mut head = None;
        let mut cur = &mut head;

        while s > 0 || !a.is_none() || !b.is_none()
        {
            if let Some(p) = a {
                s += p.val;
                a = &p.next;
            }

            if let Some(p) = b {
                s += p.val;
                b = &p.next;
            }

            cur.replace(Box::new(ListNode {
                val: s % 10,
                next: None,
            }));

            if let Some(p) = cur {
                cur = &mut p.next;
            }

            s /= 10;
        }

        return head;
    }
}
