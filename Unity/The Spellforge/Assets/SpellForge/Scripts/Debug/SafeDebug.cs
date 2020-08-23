using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using UnityEngine;

public static class SafeDebug
{
    [Conditional("DEBUG_MESSAGELOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void Log(object message) { UnityEngine.Debug.Log(message); }
    [Conditional("DEBUG_MESSAGELOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void Log(object message, Object context) { UnityEngine.Debug.Log(message, context); }

    [Conditional("DEBUG_WARNINGLOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void LogWarning(object message) { UnityEngine.Debug.LogWarning(message); }
    [Conditional("DEBUG_WARNINGLOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void LogWarning(object message, Object context) { UnityEngine.Debug.LogWarning(message, context); }

    [Conditional("DEBUG_ERRORLOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void LogError(object message) { UnityEngine.Debug.LogError(message); }
    [Conditional("DEBUG_ERRORLOG_ENABLED"), Conditional("UNITY_EDITOR")]
    public static void LogError(object message, Object context) { UnityEngine.Debug.LogError(message, context); }
}
