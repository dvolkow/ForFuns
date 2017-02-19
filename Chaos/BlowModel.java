package Chaos;

import java.util.Random;

/**
 * Created by danya on 18.02.17.
 */
public class BlowModel {
    /**
     * Simple Blow.
     * @param a first unit
     * @param b second unit
     * @param random randomizer
     * @param type true if random
     */
    public static void blowSimple(Unit a, Unit b, Random random, boolean type) {
        int tmp_vx = !type ? a.getVX() : a.getVX() + random.nextInt(2) - 1;// + unit1.getVX();
        int tmp_vy = !type ? a.getVY() : a.getVY() + random.nextInt(2) - 1;// + unit1.getVY();
        a.setVX(b.getVX());
        a.setVY(b.getVY());
        b.setVX(tmp_vx);
        b.setVY(tmp_vy);
        blowSet(a, b);
    }

    public static void swapBlowSimpleNoRandom(Unit a, Unit b) {
        int tmp_vx = a.getVX();
        int tmp_vy = a.getVY();
        a.setVX(b.getVY());
        a.setVY(b.getVX());
        b.setVX(tmp_vy);
        b.setVY(tmp_vx);
        blowSet(a, b);
    }

    public static void mathBlow(Unit a, Unit b) {

        int vx1 = a.getVX();
        int vx2 = b.getVX();
        int vy1 = a.getVY();
        int vy2 = b.getVY();

        int A = vx1 + vx2;
        int B = vy1 + vy2;
        int C = vx1 * vx1 + vy1 * vy1 - Const.DECREASE_V;
        int D = vx2 * vx2 + vy2 * vy2 - Const.DECREASE_V;

        int F = -(C + D + A * A + B * B) / 2;

        vy1 = sqRoot(A * A + B * B, -2 * B * F, F * F - A * A * C);
        vx1 = A != 0 ? (F - B * vy1) / A : 1;
        vx2 = A - vx1;
        vy2 = B - vy1;

        a.setVX(vx1);
        a.setVY(vy1);
        b.setVY(vy2);
        b.setVX(vx2);

        blowSet(a, b);
    }

    public static void mathBlow2(Unit a, Unit b) {

        int vx1 = a.getVX();
        int vx2 = b.getVX();
        int vy1 = a.getVY();
        int vy2 = b.getVY();

        double E = Math.sqrt((vx1 + vx2) * (vx1 + vx2) +
                (vy1 + vy2) * (vy1 + vy2));
        double ex = (vx1 + vx2) / E;
        double ey = (vy1 + vy2) / E;


        double aex = vx1 * ex;
        double aey = vy1 * ey;

        double bex = vx2 * ex;
        double bey = vy2 * ey;

        a.setVX((int)(2 * aex) + vx1);
        b.setVX((int)(2 * bex) + vx2);
        a.setVY((int)(2 * aey) + vy1);
        b.setVY((int)(2 * bey) + vy2);

        blowSet(a, b);
    }

    public static int sqRoot(int A, int B, int C) {
        int D = B * B - 4 * A * C;
        if (D < 0) return 0;
        int root1 = A != 0 ? (int) ((-B + Math.sqrt(D)) / (2 * A)) : (B != 0 ? -C / B : -C);
        int root2 = A != 0 ? (int) ((-B - Math.sqrt(D)) / (2 * A)) : (B != 0 ? -C / B : -C);
        return Math.max(Math.abs(root1), Math.abs(root2));
    }

    public static void blowSet(Unit a, Unit b) {
        a.blow = true;
        a.incBlow();
        b.blow = true;
        b.incBlow();
    }

}
