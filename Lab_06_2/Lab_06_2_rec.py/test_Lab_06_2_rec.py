import unittest
from Lab_06_2_rec import create_array, max_num, min_num, avg


class TestLab06_2_rec(unittest.TestCase):
    def setUp(self):
        # фіксований масив, для якого відповіді пораховано вручну
        self.t = [12, 3, -8, -9, 16, 4, -1, 9, -13, 5]

    def test_max(self):
        self.assertEqual(max_num(self.t, 1, self.t[0]), 16)

    def test_min(self):
        self.assertEqual(min_num(self.t, 1, self.t[0]), -13)

    def test_avg(self):
        biggest = max_num(self.t, 1, self.t[0])
        smallest = min_num(self.t, 1, self.t[0])
        self.assertEqual(avg(biggest, smallest), 1.5)

    def test_one_element(self):
        self.assertEqual(max_num([7], 1, 7), 7)
        self.assertEqual(min_num([7], 1, 7), 7)

    def test_create_array(self):
        t = create_array(-20, 20, 10)
        self.assertEqual(len(t), 10)
        for x in t:
            self.assertTrue(-20 <= x <= 20)


if __name__ == "__main__":
    unittest.main()
