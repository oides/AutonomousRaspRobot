package inf627.gsort.ifba.edu.br.joystick;

import android.util.Log;

/**
 * Created by eudes on 17/01/15.
 */
public class JoystickButtons {

    private boolean frente = false;
    private boolean re = false;
    private boolean esquerda = false;
    private boolean direita = false;

    public void startFrente() {
        if (!this.frente) {
            this.frente = true;

            Runnable r = new Runnable() {
                public JoystickButtons threadJoystickButtons;

                @Override
                public void run() {
                    threadJoystickButtons.executeFrente();
                }

                private Runnable init(JoystickButtons pJoystickButtons) {
                    this.threadJoystickButtons = pJoystickButtons;
                    return this;
                }
            }.init(this);

            Thread t = new Thread(r);
            t.start();
        }
    }

    public void startRe() {
        if (!this.re) {
            this.re = true;

            Runnable r = new Runnable() {
                public JoystickButtons threadJoystickButtons;

                @Override
                public void run() {
                    threadJoystickButtons.executeRe();
                }

                private Runnable init(JoystickButtons pJoystickButtons) {
                    this.threadJoystickButtons = pJoystickButtons;
                    return this;
                }
            }.init(this);

            Thread t = new Thread(r);
            t.start();
        }
    }

    public void startEsquerda() {
        if (!this.esquerda) {
            this.esquerda = true;

            Runnable r = new Runnable() {
                public JoystickButtons threadJoystickButtons;

                @Override
                public void run() {
                    threadJoystickButtons.executeEsquerda();
                }

                private Runnable init(JoystickButtons pJoystickButtons) {
                    this.threadJoystickButtons = pJoystickButtons;
                    return this;
                }
            }.init(this);

            Thread t = new Thread(r);
            t.start();
        }
    }

    public void startDireita() {
        if (!this.direita) {
            this.direita = true;

            Runnable r = new Runnable() {
                public JoystickButtons threadJoystickButtons;

                @Override
                public void run() {
                    threadJoystickButtons.executeDireita();
                }

                private Runnable init(JoystickButtons pJoystickButtons) {
                    this.threadJoystickButtons = pJoystickButtons;
                    return this;
                }
            }.init(this);

            Thread t = new Thread(r);
            t.start();
        }
    }

    public void stopFrente() {
        this.frente = false;
    }

    public void stopRe() {
        this.re = false;
    }

    public void stopEsquerda() {
        this.esquerda = false;
    }

    public void stopDireita() {
        this.direita = false;
    }

    public void executeFrente() {
        Log.v("Joystick", "INICIO FRENTE");
        while (this.frente) {
            sleep();
        }
        Log.v("Joystick", "FIM FRENTE");
    }

    public void executeRe() {
        Log.v("Joystick", "INICIO RE");
        while (this.re) {
            sleep();
        }
        Log.v("Joystick", "FIM RE");
    }

    public void executeEsquerda() {
        Log.v("Joystick", "INICIO ESQUERDA");
        while (this.esquerda) {
            sleep();
        }
        Log.v("Joystick", "FIM ESQUERDA");
    }

    public void executeDireita() {
        Log.v("Joystick", "INICIO DIREITA");
        while (this.direita) {
            sleep();
        }
        Log.v("Joystick", "FIM DIREITA");
    }

    private void sleep() {
        try
        {
            Thread.sleep(50);
        } catch (InterruptedException e)
        {
            e.printStackTrace();
        }
    }
}
