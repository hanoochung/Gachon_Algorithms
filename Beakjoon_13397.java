import java.util.Scanner;

public class Beakjoon_13397 {
    public static void main(String[] args) {
        int N, M;//N 숫자개수, M 구간개수
        int[] arr = new int[5000];//총 구간
        int start = 0, end = 0;//start,end 구간 최소최대값
        Scanner scan = new Scanner(System.in);
        N=scan.nextInt();
        M=scan.nextInt();

        for(int i=0; i< N; i++){
            arr[i]=scan.nextInt();
            if(arr[i] > end){
                end = arr[i];
            }
        }

        System.out.println("start: "+start+ "\tend: "+end);

        while(start<=end){
            int mid = (start+end)/2;
            int section_max = 0, section_min = 10001, section_count = 1;

            for (int i = 0; i < N; i++) {
                if (section_max < arr[i])
                    section_max = arr[i];
                if (section_min > arr[i])
                    section_min = arr[i];
                if (section_max - section_min > mid) { //이전 구간을 하나의 section으로 취급
                    section_count++;  //section 수 추가
                    section_max = arr[i];
                    section_min = arr[i];
                }
            }
            if (section_count > M)
                start = mid + 1;
            else
                end = mid - 1;
            System.out.println("mid"+mid+"\tstart"+start+"\tend"+end+"\tsection_count"+section_count);
        }
        System.out.println(start);
    }
}
