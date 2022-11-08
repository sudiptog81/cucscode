import java.util.ArrayList;
import java.util.Random;

/**
 * This is an implementation of ObjectPool Class that uses the
 * object pool pattern to return a random object from the pool
 * 
 * @author Sudipto Ghosh (Roll No. 27)
 *
 */
public class ObjectPool {
	private static ObjectPool _instance = null;
	private static ArrayList<Object> pool = new ArrayList<>();
	private static Random random = new Random();

	private ObjectPool() {
		random.setSeed(10);
		System.out.println("ObjectPool<" + hashCode() + "> Created");
	}

	public static ObjectPool getInstance() {
		if (_instance == null)
			_instance = new ObjectPool();
		return _instance;
	}

	public Object fetch() {
		if (pool.size() > 0) {
			int rnd = random.nextInt(pool.size());
			Object obj = pool.get(rnd);
			pool.remove(rnd);
			return obj;
		} else {
			return null;
		}
	}

	public void store(Object obj) {
		pool.add(obj);
	}

	/*
	 * Driver Code
	 */
	public static void main(String[] args) {
		ObjectPool pool = ObjectPool.getInstance();

		for (int i = 0; i < 5; i++) {
			Object obj = new Object();
			pool.store(obj);
			System.out.println("Stored Object<" + obj.hashCode()
					+ "> in ObjectPool<" + pool.hashCode() + ">");
		}

		for (int i = 0; i < 5; i++) {
			Object obj = pool.fetch();

			if (obj == null) {
				System.out.println("No Object Could Be Fetched From ObjectPool<"
						+ pool.hashCode() + ">");
				continue;
			}

			System.out.println("Fetched Object<" + obj.hashCode()
					+ "> from ObjectPool<" + pool.hashCode() + ">");
		}
	}
}
