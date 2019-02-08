import java.io.Serializable;


public class Dato implements Serializable {

	String v1;
	int v2;
	float v3;
	long v4;


	public Dato(String v1, int v2, float v3, long v4) {
		this.v1 = v1;
		this.v2 = v2;
		this.v3 = v3;
		this.v4 = v4;
	}

	String getV1() {
		return v1;
	}
	int getV2() {
		return v2;
	}
	float getV3() {
		return v3;
	}
	long getV4() {
		return v4;
	}
}