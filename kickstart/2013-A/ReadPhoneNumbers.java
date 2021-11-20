import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class ReadPhoneNumbers {
    static final Map<Integer, String> READ_MAP = Map.of(2, "double", 3, "triple", 4, "quadruple", 5, "quintuple", 6, "sextuple", 7, "septuple", 8, "octuple", 9, "nonuple", 10, "decuple");
    static final Map<Integer, String> NUM_TO_ENG = Map.of(0, "zero", 1, "one", 2, "two", 3, "three", 4, "four", 5, "five", 6, "six", 7, "seven", 8, "eight", 9, "nine");

    public static StringBuffer populateGiveNumberPronunciation(StringBuffer sb, char givenChar, int cnt) {
        if (sb == null) {
            return sb;
        }
        if (cnt > 1 && cnt < 11) {
            sb.append(READ_MAP.get(cnt) + " " + NUM_TO_ENG.get(givenChar - '0') + " ");
        } else {
            for (int j = 0; j < cnt; j++) {
                sb.append(NUM_TO_ENG.get(givenChar - '0') + " ");
            }
        }
        return sb;
    }

    public static StringBuffer givePhoneNumInEnglish(StringBuffer sb, String number, String pattern) {
        String[] order = pattern.split("-");

        int beginIndex = 0, orderId = 0;

        while (beginIndex < number.length()) {
            Integer orderValue = Integer.parseInt(order[orderId++]);
            int endIndex = beginIndex + orderValue;
            char firstValue = number.charAt(beginIndex);
            int cnt = 1;
            beginIndex += 1;
            while (beginIndex < endIndex) {
                if (firstValue == number.charAt(beginIndex)) {
                    cnt++;
                } else {
                    populateGiveNumberPronunciation(sb, firstValue, cnt);
                    firstValue = number.charAt(beginIndex);
                    cnt = 1;
                }
                beginIndex++;
            }
            populateGiveNumberPronunciation(sb, firstValue, cnt);
        }
        return sb;
    }

    public static void main(String[] args) {
        int n;
        Scanner scan = new Scanner(System.in);
        n = scan.nextInt();
        for (int i = 1; i <= n; i++) {
            StringBuffer sb = new StringBuffer();
            sb.append("Case #").append(i).append(": ");
            String num, pattern;
            num = scan.next();
            pattern = scan.next();
            sb = givePhoneNumInEnglish(sb, num, pattern);
            System.out.println(sb);
        }
    }
}
