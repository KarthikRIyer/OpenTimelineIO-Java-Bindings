package io.opentimeline;

public class FileTypeNotSupportedException extends Exception {
    public FileTypeNotSupportedException(String errorMessage) {
        super(errorMessage);
    }
}
