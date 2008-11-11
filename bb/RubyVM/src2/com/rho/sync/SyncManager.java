package com.rho.sync;

import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;

import javax.microedition.io.Connector;
import javax.microedition.io.HttpConnection;

public class SyncManager {

	public static String fetchRemoteData(String url) throws IOException {
		StringBuffer buffer = new StringBuffer();
		InputStream is = null;
		HttpConnection connection = null;
		try {
			long len = 0;
			int ch = 0;
			connection = (HttpConnection) Connector.open(url);
			is = connection.openInputStream();
			len = connection.getLength();
			if (len != -1) {
				for (int i = 0; i < len; i++) {
					if ((ch = is.read()) != -1) {
						buffer.append((char) ch);
					}
				}
			} else {
				while ((ch = is.read()) != -1) {
					buffer.append((char) ch);
				}
			}
		} finally {
			is.close();
			connection.close();
		}
		return buffer.toString();
	}

	public static int pushRemoteData(String url, String data)
			throws IOException {
		OutputStream os = null;
		HttpConnection connection = null;
		try {
			connection = (HttpConnection) Connector.open(url);
			os = connection.openOutputStream();
			connection.setRequestMethod("POST");
			connection.setRequestProperty("Content-Length", String.valueOf(data
					.length()));
			os.write(data.getBytes());
		} finally {
			os.close();
			connection.close();
		}

		return SyncConstants.SYNC_PUSH_CHANGES_OK;
	}
}