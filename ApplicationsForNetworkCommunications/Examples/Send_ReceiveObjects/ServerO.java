import java.io.*;
import java.net.*;

public class ServerO {
	public static void main(String abs[]) {

		try {

			ServerSocket s = new ServerSocket ();
			int pto = 1234;
			InetSocketAddress pto_l = new InetSocketAddress (pto);
			s.bind (pto_l);
			
			s.setReuseAddress(true);

			System.out.println ("Servicio iniciado... esperando cliente...");
			for (;;){
				Socket cl = s.accept();
				System.out.println ("Cliente conectado desde: "+ cl.getInetAddress() + ": " + cl.getPort());

				ObjectInputStream ois = new ObjectInputStream(cl.getInputStream());
				ObjectOutputStream oos = new ObjectOutputStream(cl.getOutputStream());

				Dato d2 = new Dato("hola", 2, 5.0f, 3);
				oos.writeObject(d2);

				Dato d1 = (Dato) ois.readObject();
				System.out.println("Se recibio objeto: " + d1.getV1() + " " + d1.getV2());

				oos.flush();
				oos.close();
				cl.close();
			
			}

		} catch(Exception e) {
			e.printStackTrace();
		}
	}
}