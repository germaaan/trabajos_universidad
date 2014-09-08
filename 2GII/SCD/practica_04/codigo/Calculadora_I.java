
import java.rmi.Remote;
import java.rmi.RemoteException;

public interface Calculadora_I extends Remote {

    public int sumar(int num1, int num2) throws RemoteException;

    public int restar(int num1, int num2) throws RemoteException;

    public int multiplicar(int num1, int num2) throws RemoteException;

    public double dividir(double num1, double num2) throws RemoteException;
}
