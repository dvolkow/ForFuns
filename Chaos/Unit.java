package Chaos;

import org.jetbrains.annotations.Contract;

import java.awt.*;
import java.util.Random;

/**
 * Created by danya on 18.02.17.
 */
public class Unit {

    private int x_;
    private int y_;
    private int vx_;
    private int vy_;
    private Color color_;
    boolean blow;
    private int countBlow_;
    boolean reversed;
    private boolean isFree;

    final private int radius_ = 8;
    private Random random_;

    Unit() {
        this.random_ = new Random(System.currentTimeMillis());
        this.x_ = random_.nextInt(Const.size_x);
        this.y_ = random_.nextInt(Const.size_y);
        this.vx_ = random_.nextInt(20) - 10;
        this.vy_ = random_.nextInt(20) - 10;
        color_ = Color.BLACK;
        blow = false;
        this.countBlow_ = 0;
        reversed = false;
        isFree = isFreeTest();
    }


    Unit(int x, int y, int seed) {
        this.x_ = x;
        this.y_ = y;
        blow = false;
        reversed = false;
        this.countBlow_ = 0;

        int maxV = x > Const.bound_x ? Const.MIN_StartV : Const.MAX_TMP;

        this.random_ = new Random(System.currentTimeMillis() + seed);
        this.vx_ = random_.nextInt(maxV) - maxV/2;
        this.vy_ = random_.nextInt(maxV) - maxV/2;
        this.color_ = x_ > Const.bound_x ? Color.BLUE : Color.RED;
        this.isFree = isFreeTest();
    }

    public void update(final int countStep, boolean type) {


        /*
        int newX = x_ + countStep * vx_;
        int newY = y_ + countStep * vy_;
        boolean notCrossBound = (x_ < Const.bound_x - radius_/2 && newX < Const.bound_x - radius_/2) ||
                (x_ > Const.bound_x + radius_/2 && newX > Const.bound_x + radius_/2);

        boolean isHoled;
        int holedy;
        if (newY > y_) {
            holedy = (int) (y_ + vy_ * Math.abs((double) (x_ - Const.bound_x) / (double) vx_));
        } else {
            holedy = (int) (y_ - vy_ * Math.abs((double) (x_ - Const.bound_x) / (double)(vx_)));
        }


        isHoled = (holedy < Const.size_y / 2 + Const.size_hole / 2 &&
                holedy > Const.size_y / 2 - Const.size_hole / 2);

        if ((x_ <= 0 || x_ >= Const.size_x) && !reversed) {
            vx_ = - vx_;
            reversed = true;
            x_ = newX <= 0 ? 0 : Const.size_x;

        } else if (x_ >= 0 && x_ <= Const.size_x && reversed) {
            reversed = false;
            x_ = x_ + countStep * vx_;
        } else if (newX < Const.size_x && newX > 0 && notCrossBound) {
            x_ = newX;
        } else if (!notCrossBound){
            if (isHoled )  {
                x_ = isFree ? newX : Const.bound_x;
            } else {
                vx_ = - vx_;
                reversed = true;
                x_ = x_ + countStep * vx_;
            }
        }
        if ((y_ < 0 || y_ > Const.size_y) && !reversed) {
            vy_ = - vy_;
            reversed = true;
            y_ = y_ + countStep * vy_;
            return;
        }
        if (y_ >= 0 && y_ <= Const.size_y && reversed) {
            reversed = false;
            y_ = y_ + countStep * vy_;
            return;
        }
        if (newY < Const.size_y && newY > 0) {
            y_ = newY;
        } else {
            vy_ = - vy_;
            reversed = true;
            y_ = y_ + countStep * vy_;
        }

        */
        recalcX();
        recalcY();

        this.setFree();
    }

    public void print(Graphics2D g, Color color) {
        g.setColor(color_);
        g.drawOval(x_, y_, radius_, radius_);
        g.fillOval(x_, y_, radius_, radius_);
    }



    public int getX() {
        return x_;
    }

    public int getY() {
        return y_;
    }

    public int getRadius() {
        return radius_;
    }

    public int getVX() {
        return vx_;
    }

    public int getVY() {
        return vy_;
    }

    public void setVX(int vx) {
        this.vx_ = vx;
    }

    public void setVY(int vy) {
        this.vy_ = vy;
    }

    public Color getColor() {
        return color_;
    }

    public int getCountBlow() {
        return countBlow_;
    }

    public void incBlow() {
        countBlow_++;
    }

    public double getFullVel() {
        return Math.sqrt(vx_ * vx_ + vy_ * vy_);
    }

    public void setFree() {
        this.isFree = isFreeTest();
    }

    /**
     * Call before recalcY
     */
    private void recalcX() {

        if (vx_ == 0) return;

        int newX = x_ + vx_;
        if (newX >= Const.size_x || newX <= 0) {
            vx_ = -vx_;
            x_ = newX <= 0 ? 0 : Const.size_x;
            return;
        }

        int yNew = y_ + vy_;
        int y = y_ - (x_ - Const.bound_x) * (y_ - yNew) / (x_ - newX);

        if (isCrossBound()) {
            if ((y > Const.size_y/2 + Const.size_hole/2 ||
                    y < Const.size_y/2 + Const.size_hole/2) && isFree) {
                x_ = newX;
            } else {
                x_ = Const.bound_x;
                vx_ = -vx_;
            }
            return;
        }

        x_ = newX;
    }

    /**
     * @return true if path cross the bound
     */
    @Contract(pure = true)
    private boolean isCrossBound() {
        return x_ < Const.bound_x && x_ + vx_ >= Const.bound_x ||
                (x_ > Const.bound_x && x_ + vx_ <= Const.bound_x );
    }

    private void recalcY() {

        if (vy_ == 0) return;

        int newY = y_ + vy_;
        if (newY >= Const.size_y || newY <= 0) {
            vy_ = -vy_;
            y_ = newY <= 0 ? 0 : Const.size_y;
            return;
        }
        y_ = newY;
    }

    public boolean isFreeTest() {
        return !Const.ENABLE_DEVIL || (((x_ < Const.bound_x) && (getFullVel() > Const.TRESHOLD)) ||
                ((x_ >= Const.bound_x) && (getFullVel() < Const.TRESHOLD)));
    }
}
