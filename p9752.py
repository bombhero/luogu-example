import copy


class SecureLock:
    def __init__(self):
        self.n = 0
        self.status_list = []
        self.result_list = []

    def input_status(self):
        self.n = int(input())
        for _ in range(self.n):
            tmp_status = []
            s = input()
            li = s.split(' ')
            for num in li:
                tmp_status.append(int(num))
            self.status_list.append(tmp_status)

    def execute(self):
        for status in self.status_list:
            one_result_list = []
            # Only change one number
            for pos_idx in range(5):
                for num_idx in range(1, 10):
                    new_status = copy.copy(status)
                    new_number = (status[pos_idx] + num_idx) % 10
                    new_status[pos_idx] = new_number
                    one_result_list.append(new_status)
            # Change two number
            for pos_idx in range(4):
                for num_idx in range(1, 10):
                    new_status = copy.copy(status)
                    new_number = (status[pos_idx] + num_idx) % 10
                    new_number_2 = (status[pos_idx+1] + num_idx) % 10
                    new_status[pos_idx] = new_number
                    new_status[pos_idx+1] = new_number_2
                    one_result_list.append(new_status)
            if len(self.result_list) == 0:
                self.result_list = one_result_list
                continue
            new_result_list = []
            for result in self.result_list:
                if result in one_result_list:
                    new_result_list.append(result)
            self.result_list = new_result_list
        print(len(self.result_list))


if __name__ == '__main__':
    secure_lock = SecureLock()
    secure_lock.input_status()
    secure_lock.execute()
