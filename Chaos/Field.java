package Chaos;

import javax.swing.*;
import java.awt.*;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Random;
import java.util.concurrent.TimeUnit;

/**
 * Created by danya on 18.02.17.
 */
public class Field {

    private int countLeft;
    private int countRight;
    Random random;


    Field() {
        JFrame frame=new JFrame("Chaos_Daemon v0.2");
        frame.setBounds(0, 0, Const.size_x, Const.size_y);
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        Font font = new Font("Tahoma", Font.BOLD, 35);
        Font font2 = new Font("Arial", Font.BOLD, 20);

        random = new Random(System.currentTimeMillis());


        ArrayList<Unit> everyBody = new ArrayList<Unit>();
        for (int i = 1; i < Const.COUNT; ++i) {
            everyBody.add(new Unit(random.nextInt(Const.size_x), random.nextInt(Const.size_y),
                    random.nextInt(1000)));
        }

        countLeft = inLeft(everyBody);
        countRight = Const.COUNT - countLeft;

        FileWriter fileW = null; 
        try {
            fileW = new FileWriter(String.valueOf(Const.COUNT) + "_SH_" + String.valueOf(Const.size_hole), true);
        } catch (IOException e) {
            System.out.println("Ошибка записи в файл.");
        }

        JPanel contentPane = new JPanel(){
            Graphics2D g2;

            protected void paintComponent(Graphics g){
                super.paintComponent(g);
                g2=(Graphics2D)g;
                g2.setColor(Color.BLACK);
            }
        };
        frame.setContentPane(contentPane);
        printBound(contentPane);

        for (Unit unit : everyBody) {
            unit.print((Graphics2D) contentPane.getGraphics(), Color.BLACK);
        }

        int timer = 0;
        int blowsR = 0;
        int blowB = 0;

        while (timer < Const.TIME_LIMIT) {
            ++timer;
            try {
                TimeUnit.MILLISECONDS.sleep(70);
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
            for (Unit unit : everyBody) {
                unit.update(1, false);
            }
            if (timer % 3 == 0) {
                dropBlows(everyBody);
            }
            blows(everyBody);
            frame.update(contentPane.getGraphics());

            printBound(contentPane);
            countLeft = inLeft(everyBody);
            countRight = Const.COUNT - countLeft;
            contentPane.getGraphics().setFont(font);
            contentPane.getGraphics().drawString(String.valueOf(countLeft), 30, 30);
            contentPane.getGraphics().drawString(String.valueOf(countRight), Const.size_x - 30, 30);
            contentPane.getGraphics().setFont(font2);
            contentPane.getGraphics().drawString("Time = " + String.valueOf(timer),
                    Const.size_x - 100, Const.size_y - 20);
            
            double meanR = meanV(everyBody, Color.RED);
            double meanB = meanV(everyBody, Color.BLUE);
            Const.ScanStruct tmpS = scanField(everyBody);

            contentPane.getGraphics().drawString("Red mean = " +
                            String.valueOf(meanR), 20, Const.size_y - 20);
            contentPane.getGraphics().drawString("Blue mean = " +
                    String.valueOf(meanB), Const.size_x - 120, Const.size_y - 50);

            contentPane.getGraphics().drawString(
                    String.valueOf(tmpS.bBlows) + " blows", Const.size_x - 250, Const.size_y - 20);
            contentPane.getGraphics().drawString(
                    String.valueOf(tmpS.rBlows) + " blows", 50, Const.size_y - 50);

            contentPane.getGraphics().drawString("MAX_SPEED = " + tmpS.maxVel, Const.size_x/2 - 40,
                                                Const.size_y - 15);

            try {
                logStats(fileW, meanR, meanB, timer);
            } catch (IOException e) {
                System.out.println("Ошибка ввода-вывода.");
            }
            for (Unit unit : everyBody) {
                unit.print((Graphics2D) contentPane.getGraphics(), Color.BLACK);
            }
        }
    }

    public static void main(final String[] args) {
        Field t = new Field();
    }

    private void printBound(JPanel contentPane) {
        contentPane.getGraphics().drawLine(Const.bound_x, 0,
                Const.bound_x, Const.size_y/2 - Const.size_hole/2);
        contentPane.getGraphics().drawLine(Const.bound_x, Const.size_y/2 + Const.size_hole/2,
                Const.bound_x, Const.size_y);

    }

    private static Const.ScanStruct scanField(ArrayList<Unit> units) {
        Const.ScanStruct res = new Const.ScanStruct();

        for (Unit unit : units) {
            if (unit.getColor().equals(Color.RED)) {
                res.rBlows += unit.getCountBlow();
            } else {
                res.bBlows += unit.getCountBlow();
            }

            if (unit.getFullVel() > res.maxVel) {
                res.maxVel = unit.getFullVel();
            }
        }
        return res;
    }

    private static int inLeft(ArrayList<Unit> units) {
        int res = 0;
        for (Unit unit : units) {
            if (unit.getX() < Const.bound_x) {
                ++res;
            }
        }
        return res;
    }

    private void blows(ArrayList<Unit> units) {
        for (Unit unit : units) {
            for (Unit unit1 : units) {
                if (unit != unit1) {
                    if (distance(unit, unit1) < unit.getRadius() && !unit.blow && !unit1.blow) {
                    //    unit.setVX(unit1.getVX());
                    //    unit.setVY(unit1.getVY());
                    //    unit1.setVX(tmp_vx);
                    //     unit1.setVY(tmp_vy);

                        /*
                        Unit.blow(unit, unit1);
                        */
                        BlowModel.swapBlowSimpleNoRandom(unit, unit1);
//                        BlowModel.blowSimple(unit, unit1, random, false);
                    }
                }
            }
        }
    }

    private int distance(Unit a, Unit b) {
        int dx = a.getX() - b.getX();
        int dy = a.getY() - b.getY();
        return (int) Math.sqrt((double) (dx * dx + dy * dy));
    }

    void dropBlows(ArrayList<Unit> units) {
        for (Unit unit : units) {
            unit.blow = false;
        }
    }

    static double fullVel(Unit unit) {
        return Math.sqrt(unit.getVY() * unit.getVY() +
                                        unit.getVX() * unit.getVX());
    }

    double meanV(ArrayList<Unit> units, Color color) {
        int count = 0;
        double res = 0;
        for (Unit unit : units) {
            if (unit.getColor().equals(color)) {
                res += fullVel(unit);
                count++;
            }
        }
        return count > 0 ? res/count : 0;
    }
    
    public void logStats(FileWriter file, double meanR, double meanB, int timer)
                                                                                        throws IOException {
        file.write(timer + ", " + meanR + ", " + meanB + ", " + countLeft + ", " + countRight + "\n");
        file.flush();
    } 

}
