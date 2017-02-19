package Chaos;

/**
 * Created by danya on 18.02.17.
 */
public class Const {

    static class ScanStruct {
        public int rBlows;
        public int bBlows;
        public double maxVel;

        ScanStruct() {
            rBlows = 0;
            bBlows = 0;
            maxVel = 0;
        }
    }

    final static boolean ENABLE_DEVIL = false;

    final static int size_x = 1000;
    final static int size_y = 620;

    final static int bound_x = 500;
    final static int size_hole = 25;

    final static int COUNT = 60;

    final static int MAX_TMP = 45;
    final static int MIN_StartV = 10;
    final static int TRESHOLD = 0;

    final static int TIME_LIMIT = 15_000;
    final static int DECREASE_V = 0;
}
